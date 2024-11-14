class ParkingSystem {
public:
    int bigCar;
    int mediumCar;
    int smallCar;
    ParkingSystem(int big, int medium, int small) {
        this->bigCar = big;
        this->mediumCar = medium;
        this->smallCar = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            // big car
            if(bigCar >0){
                bigCar--;
                return true;
            }
            return false;
        }
        else if(carType == 2){
            // big car
            if(mediumCar >0){
                mediumCar--;
                return true;
            }
            return false;
        }
        if(smallCar >0){
            smallCar--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);


 // we have to design the parking lot....
 */