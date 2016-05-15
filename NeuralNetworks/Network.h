#pragma once

#include "Neuron.h"

class Network
{
public:
	Network(uint32_t aNumInputs, uint32_t aNumOutputs, std::initializer_list<uint32_t> aLayerDims);
	~Network();

private:
	uint32_t mNumInputs;
	uint32_t mNumOutputs;
	std::vector<std::vector<Neuron>> mHiddenLayers;
};

