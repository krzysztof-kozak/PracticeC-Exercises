#include <iostream>
using std::cout;
using std::endl;
using std::string;

int square(int base) {
  cout << base << " do kwadratu to " << base*base << endl;
  return base*base;
}

int factorial(int n) {
  int result;

  if (n < 0) {
    cout << "Błąd, podano liczbę mniejszą od 0" << endl;
    return 1;
    };

  if(n == 0) {
    result = 1;
  } else {
    for (int i = 1; i <= n; i++) {
      result *= i;
    }
  }

  cout << "Silnia z " << n << " wynosi " << result << endl;
  return result;
}

// y = ax^2 + bx + c
int function (int a, int b, int c) {
    if (a == 0 || b == 0) {
    cout << "Błąd: współczynniki x oraz y nie mogą wynosić 0" << endl;
    return 1;
    };

  int zero_of_a_function_array[2] = {};
  int delta;
  string parabola_open;

  delta = b*b - 4*a*c;
  cout << "Delta wynosi: " << delta << endl;

  if (a*a + b == c * -1) {
    zero_of_a_function_array[0] = a;
    zero_of_a_function_array[1] = -a;

    cout << "Ilość miejsc zerowych: "<< sizeof(zero_of_a_function_array) / sizeof(zero_of_a_function_array[0]) << endl;

    cout << "Miejsce zerowe #1: " << zero_of_a_function_array[0] << endl;
    cout << "Miejsce zerowe #2: " << zero_of_a_function_array[1] << endl;
  } else {
    cout << "Brak miejsc zerowych " << endl;
  }

  if (a < 0) {
    parabola_open = "dołu";
  } else {
    parabola_open = "góry";
  }

  cout << "Ramiona paraboli są skierowane do " << parabola_open << endl;

  return 0;
}

template<typename X, typename Y>
auto calculate_mean(X arr, Y size) {
  float sum = 0;

  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }

  cout << "Średnia wynosi: " << sum / size << endl;
  return sum / size;
}

template<typename X, typename Y>
auto get_max_value(X arr, Y size) {
  auto result = arr[0];

  for (int i = 0; i < size; i++) {
    if (arr[i] > result) {
      result = arr[i];
    }
  }

  cout << "Największa wartość: " << result << endl;
  return result;
}

template<typename X, typename Y>
auto get_min_value(X arr, Y size) {
  auto result = arr[0];

  for (int i = 0; i < size; i++) {
    if (arr[i] < result) {
      result = arr[i];
    }
  }

  cout << "Najmniejsza wartość: " << result << endl;
  return result;
}



class Circle {
  private:
    float radius{};

  public:
    Circle() {
      cout << "Jestem konstruktorem bez parametrów 😢" << endl;
    };

  Circle(float value) {
    cout << "Jestem konstruktorem i posiadam parametr 😎" << endl;
    radius = value;
  };

  void set_radius(float value) {
    radius = value;
  };

  float get_radius() {
    cout << "Promień wynosi: " << radius << endl;
    return radius;
  };

  float get_area() {
    cout << "Pole wynosi: " << 3.1415 * (radius*radius) << endl;
    return 3.1415 * (radius*radius);
  }

  float get_perimeter() {
    cout << "Obwód wynosi: " << 2 * 3.1415 * radius << endl;
    return 2 * 3.1415 * radius;
  }
   
    ~Circle() {
      cout << "Jestem destruktorem! Uruchamiam się na końcu zakresu" << endl;
    };
};


class Triangle {
  private:
    float height{0};
    float base{0};

  public:
    Triangle() {
      cout << "Jestem konstruktorem bez parametrów 😢" << endl;
    };

    Triangle(float a, float h) {
      cout << "Jestem konstruktorem i posiadam parametr 😎" << endl;
      height = a;
      base = h;
    };

    void set_height(float value) {
      height = value;
    };

    void set_base(float value) {
      base = value;
    };

    float get_height() {
      cout << "Wysokość wynosi: " << height << endl;
      return height;
    };

    float get_base() {
      cout << "Podstawa wynosi: " << base << endl;
      return base;
    }

    float get_area () {
      cout << "Pole wynosi: " << 0.5 * base * height << endl;
      return 0.5 * base * height;
    }
   
    ~Triangle() {
      cout << "Jestem destruktorem! Uruchamiam się na końcu zakresu" << endl;
    };
};




int main() {

  square(8);
  cout << endl;

  factorial(0);
  factorial(6);
  factorial(-4);
  cout << endl;

  function(-1, 2, -1);
  cout << endl;

  function(2, 1, -5);
  cout << endl;

  function(0, 1, 2);
  cout << endl;

  const int array_1[5]{1, 2, 3, 4, 5};
  const int array_1_size = sizeof(array_1) / sizeof(array_1[0]);

  const float array_2[5]{1.5, 2.5, 3.5, 4.5, 5.5};
  const int array_2_size = sizeof(array_2) / sizeof(array_2[0]);

  calculate_mean(array_1, array_1_size);
  get_max_value(array_1, array_1_size);
  get_min_value(array_1, array_1_size);

  cout << endl;

  calculate_mean(array_2, array_2_size);
  get_max_value(array_2, array_2_size);
  get_min_value(array_2, array_2_size);

  cout << endl;

  Circle my_circle(6.67f);
  my_circle.get_radius();

  my_circle.set_radius(9.05f);
  my_circle.get_radius();

  my_circle.get_area();
  my_circle.get_perimeter();

  cout << endl;

  Triangle my_triangle(10.25f, 33.33f);
  my_triangle.get_base();
  my_triangle.get_height();
  my_triangle.get_area();
}