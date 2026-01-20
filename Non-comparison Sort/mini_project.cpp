#include <iostream>
#include <vector>
#include <algorithm>

struct Restaurant {
    std::string name;
    double rating;
    int price_range;
    std::string cuisine;
    double distance;
};

std::vector<Restaurant> sortRestaurants(const std::vector<Restaurant>& inputRestaurants) {
    std::vector<Restaurant> sortedRestaurants = inputRestaurants;
    // your code
    return sortedRestaurants;
}

int main() {
    // Sample list of 30 restaurants
    std::vector<Restaurant> restaurants = {
        {"Sizzling Steaks", 4.6, 2, "Steakhouse", 1.2},
        {"Pasta Paradise", 4.2, 2, "Italian", 2.5},
        {"Spicy Delights", 4.4, 1, "Mexican", 3.0},
        {"Asian Fusion Grill", 4.7, 3, "Asian Fusion", 2.1},
        {"Pizza Haven", 4.5, 2, "Pizza", 1.5},
        {"Burger Bliss", 4.3, 2, "Burgers", 1.8},
        {"Seafood Delight", 4.6, 3, "Seafood", 4.2},
        {"Vegetarian Vibes", 4.2, 2, "Vegetarian", 2.8},
        {"Sushi Sensation", 4.8, 3, "Sushi", 2.3},
        {"Mediterranean Magic", 4.4, 2, "Mediterranean", 3.7},
        {"Café Latte", 4.0, 1, "Café", 0.9},
        {"BBQ Barn", 4.5, 2, "Barbecue", 3.4},
        {"Thai Temptation", 4.7, 2, "Thai", 1.1},
        {"French Elegance", 4.9, 3, "French", 2.9},
        {"Diner Delights", 4.1, 1, "American", 1.6},
        {"Noodle Nirvana", 4.3, 2, "Asian", 2.2},
        {"Gourmet Grillhouse", 4.7, 3, "Steakhouse", 4.0},
        {"Mexican Fiesta", 4.5, 2, "Mexican", 3.6},
        {"Vegan Bliss", 4.2, 2, "Vegetarian", 1.4},
        {"Sushi Supreme", 4.6, 3, "Sushi", 2.7},
        {"Italian Ristorante", 4.4, 2, "Italian", 3.3},
        {"Taco Haven", 4.8, 2, "Mexican", 1.9},
        {"Indian Delights", 4.6, 2, "Indian", 2.6},
        {"Sizzling BBQ", 4.3, 2, "Barbecue", 3.1},
        {"Pasta Perfection", 4.7, 2, "Italian", 2.4},
        {"Café Cappuccino", 4.2, 1, "Café", 1.0},
        {"Greek Odyssey", 4.5, 2, "Mediterranean", 3.5},
        {"Burger Heaven", 4.4, 2, "Burgers", 2.0},
        {"Taste of India", 4.5, 2, "Indian", 2.2},
        {"Szechuan Palace", 4.6, 2, "Chinese", 2.3},
    };

    // Sort the restaurants using the sortRestaurants function
    std::vector<Restaurant> sortedRestaurants = sortRestaurants(restaurants);

    // Print the sorted list of restaurants
    for (const Restaurant& restaurant : sortedRestaurants) {
        std::cout << "Name: " << restaurant.name << ", Rating: " << restaurant.rating
                  << ", Price Range: " << restaurant.price_range << ", Distance: " << restaurant.distance << " km"
                  << ", Cuisine: " << restaurant.cuisine << std::endl;
    }

    return 0;
}
