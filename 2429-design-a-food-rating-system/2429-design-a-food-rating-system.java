/*
2353. 식품 등급 시스템 설계

다음을 수행할 수 있는 식품 등급 시스템을 설계하세요:

시스템에 나열된 음식 항목의 등급을 수정합니다.
시스템에서 요리 유형에 대해 가장 높은 평점을 받은 음식 항목을 반환합니다.
FoodRatings 클래스를 구현합니다:

FoodRatings(String[] foods, String[] cuisines, int[] ratings) 시스템을 초기화합니다. 음식 항목은 음식, 요리 및 등급으로 설명되며, 모두 길이가 n입니다.
foods[i]는 째 음식의 이름입니다,
요리[I] 음식의 요리 유형입니다.
ratings[i]는 째 음식의 초기 평점입니다.
void changeRating(String food, int newRating) 음식이라는 이름을 가진 음식의 등급을 변경합니다.
String highestRated(String cuisine) 지정된 요리 종류에 대해 가장 높은 평점을 가지는 음식의 이름을 리턴합니다. 동점일 경우 사전적으로 더 작은 이름의 항목을 반환합니다.
사전 순서에서 x가 y보다 앞에 오는 경우, 즉 x가 y의 접두사이거나 i가 첫 번째 위치에 있어 x[i] != y[i]인 경우, 알파벳 순서에서 x[i]가 y[i] 앞에 오는 경우 문자열 x는 사전적으로 작은 문자열 y보다 사전적으로 작다는 점에 유의하세요.

 

예제 1:
입력
["FoodRatings", "highestRated", "highestRated", "changeRating", "highestRated", "changeRating", "highestRated"]
[[["김치", "미소된장", "초밥", "무사카", "라멘", "불고기"], ["한국", "일본", "일본", "그리스", "일본", "한국"], [9, 12, 8, 15, 14, 7]], ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16], ["japanese"]]
Output
[null, "김치", "라멘", null, "초밥", null, "라멘"]

설명
FoodRatings = new FoodRatings(["김치", "미소된장", "초밥", "무사카", "라멘", "불고기"], ["한국", "일본", "일본", "그리스", "일본", "한국"], [9, 12, 8, 15, 14, 7]);
foodRatings.highestRated("korean"); // 반환 "kimchi"
                                    // "김치"는 평점 9로 가장 높은 평점을 받은 한식입니다.
foodRatings.highestRated("japanese"); // 반환 "라멘"
                                      // "라멘"은 평점이 14로 가장 높은 평점을 받은 일본 음식입니다.
foodRatings.changeRating("sushi", 16); // 이제 "초밥"의 평점은 16입니다.
foodRatings.highestRated("japanese"); // "sushi" 반환
                                      // "스시"는 평점 16으로 가장 높은 평점을 받은 일본 음식입니다.
foodRatings.changeRating("라멘", 16); // 이제 "라멘"의 평점은 16입니다.
foodRatings.highestRated("japanese"); // "라멘"을 반환합니다.
                                      // "스시"와 "라멘" 모두 평점이 16입니다.
                                      // 그러나 "라멘"은 사전적으로 "스시"보다 작습니다.
 

제약 조건:
1 <= n <= 2 * 104
n == foods.length == cuisines.length == ratings.length
1 <= foods[i].length, cuisines[i].length <= 10
foods[i], cuisines[i]는 영문 소문자로 구성됩니다.
1 <= ratings[i] <= 108
음식의 모든 문자열은 고유합니다.
food는 changeRating에 대한 모든 호출에서 시스템에서 음식 항목의 이름이 됩니다.
cuisine는 highestRated에 대한 모든 호출에 걸쳐 시스템에서 적어도 하나의 음식 항목의 요리 유형입니다.
최대 2 * 104 호출은 총 2 * 104번 변경 등급 및 최고 등급으로 호출됩니다.
*/

class FoodRatings {

    class Food {
        int rating;
        String name;
        String cuisine;
        Food (String name, String cuisine, int rating) {
            this.name = name;
            this.rating = rating;
            this.cuisine = cuisine;
        }
    }

    Map<String, PriorityQueue<Food>> qMap = new HashMap<>();
    Map<String, Food> menu = new HashMap<>();

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        for (int i = 0; i < foods.length; i++) {
            Food food = new Food(foods[i], cuisines[i], ratings[i]);
            qMap.putIfAbsent(cuisines[i], new PriorityQueue<>((a, b) -> 
            b.rating == a.rating ? a.name.compareTo(b.name) : b.rating - a.rating));
            PriorityQueue<Food> pq = qMap.get(cuisines[i]);
            pq.offer(food);
            menu.put(foods[i], food);
        }
    }
    
    public void changeRating(String foodName, int newRating) {
        Food food = menu.get(foodName);
        PriorityQueue<Food> pq = qMap.get(food.cuisine);
        pq.remove(food);
        food.rating = newRating;
        pq.offer(food);
    }
    
    public String highestRated(String cuisine) {
        return qMap.get(cuisine).peek().name;
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */