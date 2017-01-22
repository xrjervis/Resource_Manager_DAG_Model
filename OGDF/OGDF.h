#pragma once
#include <ogdf/basic/Graph.h>
#include <ogdf/fileformats/GraphIO.h>
#include <ogdf/basic/graph_generators.h>
#include <ogdf/layered/SugiyamaLayout.h>
#include <ogdf/layered/OptimalRanking.h>
#include <ogdf/layered/FastHierarchyLayout.h>
#include <ogdf/layered/BarycenterHeuristic.h>
#include <ogdf/energybased/FMMMLayout.h>
#include <ogdf/layered/DfsAcyclicSubgraph.h>
#include <ogdf/planarity/PlanarizationLayout.h>
#include <ogdf/planarity/SubgraphPlanarizer.h>
#include <ogdf/planarity/VariableEmbeddingInserter.h>
#include <ogdf/planarity/FastPlanarSubgraph.h>
#include <ogdf/orthogonal/OrthoLayout.h>
#include <ogdf/planarity/EmbedderMinDepthMaxFaceLayers.h>

#include <iostream>
using namespace std;
using namespace ogdf;

void ogdf_SetLayout(GraphAttributes *ga);