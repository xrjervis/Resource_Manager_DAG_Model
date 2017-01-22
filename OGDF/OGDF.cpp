#include "OGDF.h"

void ogdf_SetLayout(GraphAttributes *ga)
{
	PlanarizationLayout pl;

	SubgraphPlanarizer *crossMin = new SubgraphPlanarizer;

	FastPlanarSubgraph *ps = new FastPlanarSubgraph;
	ps->runs(100);
	VariableEmbeddingInserter *ves = new VariableEmbeddingInserter;
	ves->removeReinsert(rrAll);

	crossMin->setSubgraph(ps);
	crossMin->setInserter(ves);

	EmbedderMinDepthMaxFaceLayers *emb = new EmbedderMinDepthMaxFaceLayers;
	pl.setEmbedder(emb);

	OrthoLayout *ol = new OrthoLayout;
	ol->separation(20.0);
	ol->cOverhang(0.4);
	pl.setPlanarLayouter(ol);

	pl.call(*ga);
}
