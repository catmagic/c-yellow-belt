#include<iostream>
#include<vector>
int main()
{
	int N;
	std::cin>>N;
	std::vector<int64_t> temperaturesdays(N);
	int64_t sum=0;
	int64_t middleTemperatureday;
	for(int i=0;i<N;++i)
	{
		std::cin>>temperaturesdays[i];
		sum+=temperaturesdays[i];
	}
	middleTemperatureday=sum/N;
	std::vector<int64_t> res;
	for(int i=0;i<N;++i)
	{
		if(middleTemperatureday<temperaturesdays[i])
		{
			res.push_back(i);
		}

	}
	std::cout<<res.size()<<std::endl;
	for(auto numberday:res)
	{
		std::cout<<numberday<<" ";
	}
	return 0;

}
