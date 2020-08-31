#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

class FunctionPart
{
private:
    char operation;
    double value;
public:
    FunctionPart(char new_operation, double new_value){
        operation = new_operation;
        value = new_value;
    };
    

    double Apply(double source_value) const {
        switch (operation)
        {
        case '+':
            return source_value + value;
            break;
        case '-':
            return source_value - value;
            break;    
        case '*':
            return source_value * value;
            break;
        case '/':
            return source_value / value;
            break;    
        default:
            break;
        }
        return 0;
    };
    void Invert() {
        switch (operation)
        {
        case '+':
            operation = '-';
            break;
        case '-':
            operation = '+';
            break;    
        case '*':
            operation = '/';
            break;
        case '/':
            operation = '*';
            break;    
        default:
            break;
        }
        
    }
};



class Function
{
private:
    /* data */
    vector<FunctionPart> parts;
public:
    
    void AddPart(char operation, double value){
        parts.push_back({operation, value});
    }
    double Apply( double value) const{
        for (const FunctionPart& part : parts) {
            value = part.Apply(value);
        }
        return value;
    }
    void Invert(){
        for (FunctionPart& part : parts) {
            part.Invert();
        }
        reverse(begin(parts),end(parts));
    };
};


Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 52) << endl;
  return 0;
}
