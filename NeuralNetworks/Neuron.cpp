#include "stdafx.h"
#include "Neuron.h"

Neuron::Neuron(uint32_t aNumWeights) :
	mWeights(aNumWeights)
{
	static std::default_random_engine randEng;
	static std::uniform_real_distribution<float> randDist(0.0f, 1.0f);
	std::generate(mWeights.begin(), mWeights.end(), [&]() { return randDist(randEng); });
}

Neuron::~Neuron()
{
}

float Neuron::feedForward(const std::vector<float> &aInputs) const
{
	float weightedSum = std::inner_product(mWeights.begin(), mWeights.end(), aInputs.begin(), mBias);
	float firingRate = 1.0f / (1.0f + expf(-weightedSum));
	return firingRate;
}

std::ostream& operator<<(std::ostream& os, const Neuron &aNeuron)
{
	std::cout << "WEIGHTS: ";
	for (const auto &weight : aNeuron.mWeights)
	{
		std::cout << weight << " ";
	}
	std::cout << '\n';
	std::cout << "BIAS: " << aNeuron.mBias << std::endl;
	return os;
}