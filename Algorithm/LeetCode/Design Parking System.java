// 1603. Design Parking System (https://leetcode.com/problems/design-parking-system)

class ParkingSystem {
    int big;
    int medium;
    int small;

    public ParkingSystem(int big, int medium, int small) {
        this.big = big;
        this.medium = medium;
        this.small = small;
    }
    
    public boolean addCar(int carType) {
        switch (carType) {
            case 1 : big--; return big >= 0;
            case 2 : medium--; return medium >= 0;
            case 3 : small--; return small >= 0;
        }
        return false;
    }
}

/**
 * 주차 시스템 개체가 인스턴스화되고 다음과 같이 호출됩니다:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */

 class ParkingSystem2 {
    int[] count;

    public ParkingSystem2(int big, int medium, int small) {
        count = new int[]{big, medium, small};
    }
    
    public boolean addCar(int carType) {
        return count[carType - 1]-- > 0;
    }
}
