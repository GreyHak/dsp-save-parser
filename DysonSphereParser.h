//
// Copyright (c) 2021, Aaron Shumate
// All rights reserved.
//
// This source code is licensed under the BSD-style license found in the
// LICENSE.txt file in the root directory of this source tree. 
//
// Dyson Sphere Program is developed by Youthcat Studio and published by Gamera Game.

#pragma once

#include <cinttypes>
#include <string>
#include <vector>
#include <map>
#include <fstream>

const float oilSpeedMultiplier = 4E-05f;

class DysonSphereParser
{
public:
    class IntVector2
    {
    public:
        IntVector2();
        void parse(std::ifstream& strm);

        int32_t x;
        int32_t y;
    };

    class Vector3
    {
    public:
        Vector3();
        void parse(std::ifstream& strm);

        float x;
        float y;
        float z;
    };

    class VectorLF3
    {
    public:
        VectorLF3();
        void parse(std::ifstream& strm);

        double x;
        double y;
        double z;
    };

    class Quaternion
    {
    public:
        Quaternion();
        void parse(std::ifstream& strm);

        float x;
        float y;
        float z;
        float w;
    };

    class GameDesc
    {
    public:
        GameDesc();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t galaxyAlgo;
        int32_t galaxySeed;
        int32_t starCount;
        int32_t playerProto;
        float resourceMultiplier;
        int32_t numThemeIds;
        std::vector<int32_t> themeIds;
    };

    class GamePrefsData
    {
    public:
        GamePrefsData();
        void parse(std::ifstream& strm);

        int32_t version;
        VectorLF3 cameraUPos;
        Quaternion cameraURot;
        int32_t reformCursorSize;
        int32_t numReplicatorMultipliers;
        std::map<int32_t, int32_t> replicatorMultipliers;
        bool detailPower;
        bool detailVein;
        bool detailSpaceGuide;
        bool detailSign;
        bool detailIcon;
        int32_t numTutorialShowing;
        std::vector<int32_t> tutorialShowing;
    };

    class TechState
    {
    public:
        TechState();
        void parse(std::ifstream& strm);

        int32_t techProtoIndex;
        bool unlocked;
        int32_t curLevel;
        int32_t maxLevel;
        int64_t hashUploaded;
        int64_t hashNeeded;
    };

    class GameHistoryData
    {
    public:
        GameHistoryData();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t numRecipeUnlocked;
        std::vector<int32_t> recipeUnlocked;
        int32_t numTutorialUnlocked;
        std::vector<int32_t> tutorialUnlocked;
        int32_t numFeatureKeys;
        std::vector<int32_t> featureKeys;
        int32_t numTechState;
        std::vector<TechState> techStates;
        bool autoManageLabItems;
        int32_t currentTech;
        int32_t numTechQueue;
        std::vector<int32_t> techQueue;
        int32_t universeObserveLevel;
        float solarSailLife;
        float solarEnergyLossRate;
        bool useIonLayer;
        int32_t inserterStackCount;
        float logisticDroneSpeed;
        float logisticDroneSpeedScale;
        int32_t logisticDroneCarries;
        float logisticShipSailSpeed;
        float logisticShipWarpSpeed;
        float logisticShipSpeedScale;
        bool logisticShipWarpDrive;
        int32_t logisticShipCarries;
        float miningCostRate;
        float miningSpeedScale;
        int32_t storageLevel;
        int32_t labLevel;
        int32_t techSpeed;
        float dysonNodeLatitude;
        int64_t universeMatrixPointUploaded;
        bool missionAccomplished;
    };

    class ProductStat
    {
    public:
        ProductStat();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t numCount;
        std::vector<int32_t> count;
        int32_t numCursor;
        std::vector<int32_t> cursor;
        int32_t numTotal;
        std::vector<int32_t> total;
        int32_t itemId;
    };

    class PowerStat
    {
    public:
        PowerStat();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t numEnergy;
        std::vector<int64_t> energy;
        int32_t numCursor;
        std::vector<int32_t> cursor;
        int32_t numTotal;
        std::vector<int64_t> total;
        int32_t itemId;
    };

    class FactoryProductionStat
    {
    public:
        FactoryProductionStat();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t productCapacity;
        int32_t productCursor;
        std::vector<ProductStat> productPool;
        int32_t numPowerPool;
        std::vector<PowerStat> powerPool;
        int32_t numProductIndices;
        std::vector<int32_t> productIndices;
        int64_t energyConsumption;
    };

    class ProductionStatistics
    {
    public:
        ProductionStatistics();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t numFactoryStatPool;
        std::vector<FactoryProductionStat> factoryStatPool;
        int32_t numFirstCreateIds;
        std::vector<int32_t> firstCreateIds;
        int32_t numFavoriteIds;
        std::vector<int32_t> favoriteIds;
    };

    class GameStatData
    {
    public:
        GameStatData();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t numTechHashedHistory;
        std::vector<int32_t> techHashedHistory;
        ProductionStatistics production;
    };

    class StorageComponent
    {
    public:
        StorageComponent();
        void parse(std::ifstream& strm);

        struct GRID
        {
            int32_t itemId;
            int32_t filter;
            int32_t count;
            int32_t stackSize;
        };

        int32_t version;
        int32_t id;
        int32_t entityId;
        int32_t previous;
        int32_t next;
        int32_t bottom;
        int32_t top;
        enum class EStorageType { Default = 0, Fuel = 1, Filtered = 9 };
        EStorageType type;
        int32_t gridSize;
        int32_t bans;
        std::vector<GRID> grids;
    };

    class ForgeTask
    {
    public:
        ForgeTask();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t recipeId;
        int32_t count;
        int32_t tick;
        int32_t tickSpend;
        int32_t numItem;
        int32_t numProduct;
        std::vector<int32_t> itemIds;
        std::vector<int32_t> itemCounts;
        std::vector<int32_t> served;
        std::vector<int32_t> productIds;
        std::vector<int32_t> productCounts;
        std::vector<int32_t> produced;
        int32_t parentTaskIndex;
    };

    class MechaForge
    {
    public:
        MechaForge();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t numTasks;
        std::vector<ForgeTask> tasks;
    };

    class MechaLab
    {
    public:
        MechaLab();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t numItemPoints;
        std::map<int32_t, int32_t> itemPoints;
    };

    class MechaDrone
    {
    public:
        MechaDrone();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t stage;
        Vector3 position;
        Vector3 target;
        Vector3 forward;
        float speed;
        int32_t movement;
        int32_t targetObject;
        float progress;
        Vector3 initialVector;
    };

    class Mecha
    {
    public:
        Mecha();
        void parse(std::ifstream& strm);

        int32_t version;
        double coreEnergyCap;
        double coreEnergy;
        double corePowerGen;
        double reactorPowerGen;
        double reactorEnergy;
        int32_t reactorItemId;
        StorageComponent reactorStorage;
        StorageComponent warpStorage;
        double walkPower;
        double jumpEnergy;
        double thrustPowerPerAcc;
        double warpKeepingPowerPerSpeed;
        double warpStartPowerPerSpeed;
        double miningPower;
        double replicatePower;
        double researchPower;
        double droneEjectEnergy;
        double droneEnergyPerMeter;
        int32_t coreLevel;
        int32_t thrusterLevel;
        float miningSpeed;
        float replicateSpeed;
        float walkSpeed;
        float jumpSpeed;
        float maxSailSpeed;
        float maxWarpSpeed;
        float buildArea;
        MechaForge forge;
        MechaLab lab;
        int32_t droneCount;
        float droneSpeed;
        int32_t droneMovement;
        std::vector<MechaDrone> drones;
    };

    class PlayerNavigation
    {
    public:
        PlayerNavigation();
        void parse(std::ifstream& strm);

        int32_t version;
        bool navigating;
        int32_t naviAstroId;
        VectorLF3 naviTarget;
        bool useFly;
        bool useSail;
        bool useWarp;
        enum class ENaviStage { None, Departure, OriginOrbit, AccOrbit, Space, DestOrbit, Approaching };
        ENaviStage stage;
        double flyThreshold;
        double sailThreshold;
        double warpThreshold;
        double maxSailSpeed;
    };

    class Player
    {
    public:
        Player();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t planetId;
        Vector3 position;
        VectorLF3 uPosition;
        Quaternion uRotation;
        enum class EMovementState { Walk, Drift, Fly, Sail };
        EMovementState movementState;
        float warpState;
        bool warpCommand;
        VectorLF3 uVelocity;
        int32_t inhandItemId;
        int32_t inhandItemCount;
        Mecha mecha;
        StorageComponent package;
        PlayerNavigation navigation;
        int32_t sandCount;
    };

    class GalacticTransport
    {
    public:
        GalacticTransport();
        void parse(std::ifstream& strm);

        int32_t version;
    };

    enum class EVeinType
    {
        None, Iron, Copper, Silicium, Titanium, Stone, Coal, Oil, Fireice, Diamond, Fractal, Crysrub, Grat, Bamboo, Mag
    };

    static const char* toString(const EVeinType type)
    {
        if (type == EVeinType::None) return "None";
        if (type == EVeinType::Iron) return "Iron Ore";
        if (type == EVeinType::Copper) return "Copper Ore";
        if (type == EVeinType::Silicium) return "Silicon Ore";
        if (type == EVeinType::Titanium) return "Titanium Ore";
        if (type == EVeinType::Stone) return "Stone Ore";
        if (type == EVeinType::Coal) return "Coal Ore";
        if (type == EVeinType::Oil) return "Crude Oil";
        if (type == EVeinType::Fireice) return "Fire Ice";
        if (type == EVeinType::Diamond) return "Kimberlite Ore";
        if (type == EVeinType::Fractal) return "Fractal Silicon";
        if (type == EVeinType::Crysrub) return "Crysrub";  // ? Spiniform Stalagmite Crystal
        if (type == EVeinType::Grat) return "Optical Grating Crystal";
        if (type == EVeinType::Bamboo) return "Bamboo";  // ?
        if (type == EVeinType::Mag) return "Unipolar Magnet";
        return "ERROR";
    }

    class VeinGroup
    {
    public:
        VeinGroup();
        void parse(std::ifstream& strm);

        EVeinType type;
        Vector3 pos;
        int32_t count;
        int64_t amount;
    };

    class PlanetData
    {
    public:
        PlanetData();
        void parse(std::ifstream& strm);

        int32_t modDataByteCount;
        std::vector<uint8_t> modData;
        int32_t numVeinAmounts;
        std::vector<int64_t> veinAmounts;  // The index is the EVeinType.  This contains the total of the veinGroups's amounts which is also the total of the VeinData::amounts.
        int32_t numVeinGroups;
        std::vector<VeinGroup> veinGroups;
    };

    class EntityData
    {
    public:
        EntityData();
        void parse(std::ifstream& strm);

        uint8_t version;
        int32_t id;
        int16_t protoId;
        int16_t modelIndex;
        Vector3 pos;
        Quaternion rot;
        int32_t beltId;
        int32_t splitterId;
        int32_t storageId;
        int32_t tankId;
        int32_t minerId;
        int32_t inserterId;
        int32_t assemblerId;
        int32_t fractionateId;
        int32_t ejectorId;
        int32_t siloId;
        int32_t labId;
        int32_t stationId;
        int32_t powerNodeId;
        int32_t powerGenId;
        int32_t powerConId;
        int32_t powerAccId;
        int32_t powerExcId;
        int32_t monsterId;
    };

    class AnimData
    {
    public:
        AnimData();
        void parse(std::ifstream& strm);

        float time;
        float prepare_length;
        float working_length;
        uint32_t state;
        float power;
    };

    class SignData
    {
    public:
        SignData();
        void parse(std::ifstream& strm);

        uint32_t signType;
        uint32_t iconType;
        uint32_t iconId0;
        uint32_t iconId1;
        uint32_t iconId2;
        uint32_t iconId3;
        float count0;
        float count1;
        float count2;
        float count3;
        float x;
        float y;
        float z;
        float w;
    };

    class PrebuildData
    {
    public:
        PrebuildData();
        void parse(std::ifstream& strm);

        uint8_t version;
        int32_t id;
        int16_t protoId;
        int16_t modelIndex;
        Vector3 pos;
        Quaternion rot;
        Vector3 pos2;
        Quaternion rot2;
        int32_t upEntity;
        int16_t pickOffset;
        int16_t insertOffset;
        int32_t recipeId;
        int32_t filterId;
        int32_t refCount;
        std::vector<int32_t> refArr;
    };

    class VegeData
    {
    public:
        VegeData();
        void parse(std::ifstream& strm);

        uint8_t version;
        int32_t id;
        int16_t protoId;
        int16_t modelIndex;
        int16_t hp;
        Vector3 pos;
        Quaternion rot;
        Vector3 scl;
    };

    class VeinData
    {
    public:
        VeinData();
        void parse(std::ifstream& strm);

        uint8_t version;
        int32_t id;
        EVeinType type;
        int16_t modelIndex;
        int16_t groupIndex;
        int32_t amount;
        int32_t productId;
        Vector3 pos;
        int32_t minerCount;
        int32_t minerId0;
        int32_t minerId1;
        int32_t minerId2;
        int32_t minerId3;
    };

    class Cargo
    {
    public:
        Cargo();
        void parse(std::ifstream& strm);

        int32_t item;
        Vector3 position;
        Quaternion rotation;
    };

    class CargoContainer
    {
    public:
        CargoContainer();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t poolCapacity;
        int32_t cursor;
        int32_t recycleBegin;
        int32_t recycleEnd;
        std::vector<Cargo> cargoPool;
        std::vector<int32_t> recycleIds;
    };

    class BeltComponent
    {
    public:
        BeltComponent();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t entityId;
        int32_t speed;
        int32_t segPathId;
        int32_t segIndex;
        int32_t segPivotOffset;
        int32_t segLength;
        int32_t outputId;
        int32_t backInputId;
        int32_t leftInputId;
        int32_t rightInputId;
    };

    class SplitterComponent
    {
    public:
        SplitterComponent();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t entityId;
        int32_t beltA;
        int32_t beltB;
        int32_t beltC;
        int32_t beltD;
        int32_t input0;
        int32_t input1;
        int32_t input2;
        int32_t input3;
        int32_t output0;
        int32_t output1;
        int32_t output2;
        int32_t output3;
        bool inPriority;
        bool outPriority;
        int32_t outFilter;
    };

    class CargoPath
    {
    public:
        CargoPath();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t capacity;
        int32_t bufferLength;
        int32_t chunkCapacity;
        int32_t chunkCount;
        int32_t updateLen;
        bool closed;
        int32_t outputPathIdForImport;
        int32_t outputIndex;
        int32_t numBelts;
        int32_t numInputPaths;
        std::vector<uint8_t> buffer;
        std::vector<int32_t> chunks;
        std::vector<Vector3> pointPos;
        std::vector<Quaternion> pointRot;
        std::vector<int32_t> belts;
        std::vector<int32_t> inputPaths;
    };

    class CargoTraffic
    {
    public:
        CargoTraffic();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t beltCursor;
        int32_t beltCapacity;
        int32_t beltRecycleCursor;
        int32_t splitterCursor;
        int32_t splitterCapacity;
        int32_t splitterRecycleCursor;
        int32_t pathCursor;
        int32_t pathCapacity;
        int32_t pathRecycleCursor;
        std::vector<BeltComponent> beltPool;
        std::vector<int32_t> beltRecycle;
        std::vector<SplitterComponent> splitterPool;
        std::vector<int32_t> splitterRecycle;
        std::vector<int32_t> cargoPathIndex;
        std::vector<CargoPath> pathPool;
        std::vector<int32_t> pathRecycle;
    };

    class TankComponent
    {
    public:
        TankComponent();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t entityId;
        int32_t lastTankId;
        int32_t nextTankId;
        int32_t belt0;
        int32_t belt1;
        int32_t belt2;
        int32_t belt3;
        bool isOutput0;
        bool isOutput1;
        bool isOutput2;
        bool isOutput3;
        int32_t fluidStorageCount;
        int32_t currentCount;
        int32_t fluidId;
        bool outputSwitch;
        bool inputSwitch;
        bool isBottom;
    };

    class FactoryStorage
    {
    public:
        FactoryStorage();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t storageCursor;
        int32_t storageCapacity;
        int32_t storageRecycleCursor;
        std::vector<int32_t> storagePoolIndex;
        std::vector<int32_t> storagePoolSize;
        std::vector<StorageComponent> storagePool;
        std::vector<int32_t> storageRecycle;
        int32_t tankCapacity;
        int32_t tankCursor;
        int32_t tankRecycleCursor;
        std::vector<TankComponent> tankPool;
        std::vector<int32_t> tankRecycle;
    };

    class PowerGeneratorComponent
    {
    public:
        PowerGeneratorComponent();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t entityId;
        int32_t networkId;
        bool photovoltaic;
        bool wind;
        bool gamma;
        int64_t genEnergyPerTick;
        int64_t useFuelPerTick;
        int16_t fuelMask;
        int64_t fuelEnergy;
        int16_t curFuelId;
        int16_t fuelId;
        int16_t fuelCount;
        int64_t fuelHeat;
        int32_t catalystId;
        int32_t catalystPoint;
        int32_t productId;
        float productCount;
        int64_t productHeat;
        float warmup;
        float ionEnhance;
        float x;
        float y;
        float z;
    };

    class PowerNodeComponent
    {
    public:
        PowerNodeComponent();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t entityId;
        int32_t networkId;
        bool isCharger;
        int32_t workEnergyPerTick;
        int32_t idleEnergyPerTick;
        int32_t requiredEnergy;
        Vector3 powerPoint;
        float connectDistance;
        float coverRadius;
    };

    class PowerConsumerComponent
    {
    public:
        PowerConsumerComponent();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t entityId;
        int32_t networkId;
        Vector3 plugPos;
        int64_t requiredEnergy;
        int64_t servedEnergy;
        int64_t workEnergyPerTick;
        int64_t idleEnergyPerTick;
    };

    class PowerAccumulatorComponent
    {
    public:
        PowerAccumulatorComponent();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t entityId;
        int32_t networkId;
        int64_t inputEnergyPerTick;
        int64_t outputEnergyPerTick;
        int64_t curEnergy;
        int64_t maxEnergy;
    };

    class PowerExchangerComponent
    {
    public:
        PowerExchangerComponent();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t entityId;
        int32_t networkId;
        int16_t emptyCount;
        int16_t fullCount;
        float targetState;
        float state;
        int64_t energyPerTick;
        int64_t curPoolEnergy;
        int64_t poolMaxEnergy;
        int32_t emptyId;
        int32_t fullId;
        int32_t belt0;
        int32_t belt1;
        int32_t belt2;
        int32_t belt3;
        bool isOutput0;
        bool isOutput1;
        bool isOutput2;
        bool isOutput3;
        int32_t outputSlot;
        int32_t inputSlot;
        int32_t outputRectify;
        int32_t inputRectify;
    };

    class PowerNetworkStructures_Node
    {
    public:
        PowerNetworkStructures_Node();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        float x;
        float y;
        float z;
        float connDistance2;
        float coverRadius2;
        int32_t genId;
        int32_t accId;
        int32_t excId;
        int32_t numConnIdsForLoad;
        int32_t numLineIdsForLoad;
        int32_t numConsumers;
        std::vector<int32_t> connIdsForLoad;
        std::vector<int32_t> lineIdsForLoad;
        std::vector<int32_t> consumers;
    };

    class PowerNetwork
    {
    public:
        PowerNetwork();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t numNodes;
        int32_t numConsumers;
        int32_t numGenerators;
        int32_t numAccumulators;
        int32_t numExchangers;
        std::vector<PowerNetworkStructures_Node> nodes;
        std::vector<int32_t> consumers;
        std::vector<int32_t> generators;
        std::vector<int32_t> accumulators;
        std::vector<int32_t> exchangers;
    };

    class PowerSystem
    {
    public:
        PowerSystem();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t generatorCapacity;
        int32_t genCursor;
        int32_t genRecycleCursor;
        std::vector<PowerGeneratorComponent> genPool;
        std::vector<int32_t> genRecycle;
        int32_t nodeCapacity;
        int32_t nodeCursor;
        int32_t nodeRecycleCursor;
        std::vector<PowerNodeComponent> nodePool;
        std::vector<int32_t> nodeRecycle;
        int32_t consumerCapacity;
        int32_t consumerCursor;
        int32_t consumerRecycleCursor;
        std::vector<PowerConsumerComponent> consumerPool;
        std::vector<int32_t> consumerRecycle;
        int32_t accumulatorCapacity;
        int32_t accCursor;
        int32_t accRecycleCursor;
        std::vector<PowerAccumulatorComponent> accPool;
        std::vector<int32_t> accRecycle;
        int32_t exchangerCapacity;
        int32_t excCursor;
        int32_t excRecycleCursor;
        std::vector<PowerExchangerComponent> excPool;
        std::vector<int32_t> excRecycle;
        int32_t networkCapacity;
        int32_t netCursor;
        int32_t netRecycleCursor;
        std::vector<int32_t> powerNetworkIncludedFlag;
        std::vector<PowerNetwork> netPool;
        std::vector<int32_t> netRecycle;
    };

    class MinerComponent
    {
    public:
        MinerComponent();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t entityId;
        int32_t pcId;
        enum class EMinerType { None, Water, Vein, Oil };
        EMinerType type;
        int32_t speed;
        int32_t time;
        int32_t period;
        int32_t insertTarget;
        enum class EWorkState { Idle, Running, Outputing, Lack, Full };
        EWorkState workstate;
        int32_t veinCount;
        std::vector<int32_t> veins;
        int32_t currentVeinIndex;
        int32_t minimumVeinAmount;
        int32_t productId;
        int32_t productCount;
        uint32_t seed;
    };

    class InserterComponent
    {
    public:
        InserterComponent();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t entityId;
        int32_t pcId;
        enum class EInserterStage { Picking, Sending, Inserting, Returning };
        EInserterStage stage;
        int32_t speed;
        int32_t time;
        int32_t stt;
        int32_t delay;
        int32_t pickTarget;
        int32_t insertTarget;
        bool careNeeds;
        bool canStack;
        int16_t pickOffset;
        int16_t insertOffset;
        int32_t filter;
        int32_t itemId;
        int32_t stackCount;
        int32_t stackSize;
        Vector3 pos2;
        Quaternion rot2;
        int16_t t1;
        int16_t t2;
    };

    class AssemblerComponent
    {
    public:
        AssemblerComponent();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t entityId;
        int32_t pcId;
        bool replicating;
        bool outputing;
        int32_t speed;
        int32_t time;
        int32_t recipeId;
        enum class ERecipeType { None = 0, Smelt = 1, Chemical = 2, Refine = 3, Assemble = 4, Particle = 5, Exchange = 6, PhotonStore = 7, Fractionate = 8, Research = 15 };
        ERecipeType recipeType;
        int32_t timeSpend;
        int32_t numRequires;
        std::vector<int32_t> requires;
        int32_t numRequireCounts;
        std::vector<int32_t> requireCounts;
        int32_t numServed;
        std::vector<int32_t> served;
        int32_t numNeeds;
        std::vector<int32_t> needs;
        int32_t numProducts;
        std::vector<int32_t> products;
        int32_t numProductCounts;
        std::vector<int32_t> productCounts;
        int32_t numProduced;
        std::vector<int32_t> produced;
    };

    class FractionateComponent
    {
    public:
        FractionateComponent();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t entityId;
        int32_t pcId;
        int32_t belt0;
        int32_t belt1;
        int32_t belt2;
        bool isOutput0;
        bool isOutput1;
        bool isOutput2;
        bool isWorking;
        float produceProb;
        int32_t need;
        int32_t product;
        int32_t needCurrCount;
        int32_t productCurrCount;
        int32_t oriProductCurrCount;
        int32_t progress;
        bool isRand;
        bool fractionateSuccess;
        int32_t needMaxCount;
        int32_t productMaxCount;
        int32_t oriProductMaxCount;
        uint32_t seed;
    };

    class EjectorComponent
    {
    public:
        EjectorComponent();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t entityId;
        int32_t planetId;
        int32_t pcId;
        int32_t direction;
        int32_t time;
        bool fired;
        int32_t chargeSpend;
        int32_t coldSpend;
        int32_t bulletId;
        int32_t bulletCount;
        int32_t orbitId;
        float pivotY;
        float muzzleY;
        Vector3 localPosN;
        float localAlt;
        Quaternion localRot;
        Vector3 localDir;
    };

    class SiloComponent
    {
    public:
        SiloComponent();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t entityId;
        int32_t planetId;
        int32_t pcId;
        int32_t direction;
        int32_t time;
        bool fired;
        int32_t chargeSpend;
        int32_t coldSpend;
        int32_t bulletId;
        int32_t bulletCount;
        int32_t autoIndex;
        bool hasNode;
        Vector3 localPos;
        Quaternion localRot;
    };

    class LabComponent
    {
    public:
        LabComponent();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t entityId;
        int32_t pcId;
        int32_t nextLabId;
        bool replicating;
        bool outputing;
        int32_t time;
        int32_t hashBytes;
        bool researchMode;
        int32_t recipeId;
        int32_t techId;
        int32_t timeSpend;
        int32_t numRequires;
        std::vector<int32_t> requires;
        int32_t numRequireCounts;
        std::vector<int32_t> requireCounts;
        int32_t numServed;
        std::vector<int32_t> served;
        int32_t numNeeds;
        std::vector<int32_t> needs;
        int32_t numProducts;
        std::vector<int32_t> products;
        int32_t numProductCounts;
        std::vector<int32_t> productCounts;
        int32_t numProduced;
        std::vector<int32_t> produced;
        int32_t numMatrixPoints;
        std::vector<int32_t> matrixPoints;
        int32_t numMatrixServed;
        std::vector<int32_t> matrixServed;
    };

    class FactorySystem
    {
    public:
        FactorySystem();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t minerCapacity;
        int32_t minerCursor;
        int32_t minerRecycleCursor;
        std::vector<MinerComponent> minerPool;
        std::vector<int32_t> minerRecycle;
        int32_t inserterCapacity;
        int32_t inserterCursor;
        int32_t inserterRecycleCursor;
        std::vector<InserterComponent> inserterPool;
        std::vector<int32_t> inserterRecycle;
        int32_t assemblerCapacity;
        int32_t assemblerCursor;
        int32_t assemblerRecycleCursor;
        std::vector<AssemblerComponent> assemblerPool;
        std::vector<int32_t> assemblerRecycle;
        int32_t fractionateCapacity;
        int32_t fractionateCursor;
        int32_t fractionateRecycleCursor;
        std::vector<FractionateComponent> fractionatePool;
        std::vector<int32_t> fractionateRecycle;
        int32_t ejectorCapacity;
        int32_t ejectorCursor;
        int32_t ejectorRecycleCursor;
        std::vector<EjectorComponent> ejectorPool;
        std::vector<int32_t> ejectorRecycle;
        int32_t siloCapacity;
        int32_t siloCursor;
        int32_t siloRecycleCursor;
        std::vector<SiloComponent> siloPool;
        std::vector<int32_t> siloRecycle;
        int32_t labCapacity;
        int32_t labCursor;
        int32_t labRecycleCursor;
        std::vector<LabComponent> labPool;
        std::vector<int32_t> labRecycle;
    };

    class DroneData
    {
    public:
        DroneData();
        void parse(std::ifstream& strm);

        int32_t version;
        Vector3 begin;
        Vector3 end;
        int32_t endId;
        float direction;
        float maxt;
        float t;
        int32_t itemId;
        int32_t itemCount;
        int32_t gene;
    };

    class LocalLogisticOrder
    {
    public:
        LocalLogisticOrder();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t otherStationId;
        int32_t thisIndex;
        int32_t otherIndex;
        int32_t itemId;
        int32_t thisOrdered;
        int32_t otherOrdered;
    };

    class ShipData
    {
    public:
        ShipData();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t stage;
        int32_t planetA;
        int32_t planetB;
        VectorLF3 uPos;
        Vector3 uVel;
        float uSpeed;
        float warpState;
        Quaternion uRot;
        Vector3 uAngularVel;
        float uAngularSpeed;
        VectorLF3 pPosTemp;
        Quaternion pRotTemp;
        int32_t otherGId;
        int32_t direction;
        float t;
        int32_t itemId;
        int32_t itemCount;
        int32_t gene;
        int32_t shipIndex;
        int32_t warperCnt;
    };

    class RemoteLogisticOrder
    {
    public:
        RemoteLogisticOrder();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t otherStationGId;
        int32_t thisIndex;
        int32_t otherIndex;
        int32_t itemId;
        int32_t thisOrdered;
        int32_t otherOrdered;
    };

    class StationStore
    {
    public:
        StationStore();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t itemId;
        int32_t count;
        int32_t localOrder;
        int32_t remoteOrder;
        int32_t max;
        enum class ELogisticStorage { None, Supply, Demand };
        ELogisticStorage localLogic;
        ELogisticStorage remoteLogic;
    };

    class SlotData
    {
    public:
        SlotData();
        void parse(std::ifstream& strm);

        int32_t dir;
        int32_t beltId;
        int32_t storageIdx;
        int32_t counter;
    };

    class StationComponent
    {
    public:
        StationComponent();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t gid;
        int32_t entityId;
        int32_t planetId;
        int32_t pcId;
        int32_t gene;
        Vector3 droneDock;
        Vector3 shipDockPos;
        Quaternion shipDockRot;
        bool isStellar;
        int32_t nameIsIncludedFlag;
        std::string name;
        int64_t energy;
        int64_t energyPerTick;
        int64_t energyMax;
        int32_t warperCount;
        int32_t warperMaxCount;
        int32_t idleDroneCount;
        int32_t workDroneCount;
        int32_t workDroneArraySize;
        std::vector<DroneData> workDroneDatas;
        std::vector<LocalLogisticOrder> workDroneOrders;
        int32_t idleShipCount;
        int32_t workShipCount;
        uint64_t idleShipIndices;
        uint64_t workShipIndices;
        int32_t arraySize;
        std::vector<ShipData> workShipDatas;
        std::vector<RemoteLogisticOrder> workShipOrders;
        int32_t numStorage;
        std::vector<StationStore> storage;
        int32_t numSlots;
        std::vector<SlotData> slots;
        int32_t localPairProcess;
        int32_t remotePairProcess;
        int32_t nextShipIndex;
        bool isCollector;
        int32_t numCollectionIds;
        std::vector<int32_t> collectionIds;
        int32_t numCollectionPerTick;
        std::vector<float> collectionPerTick;
        int32_t numCurrentCollections;
        std::vector<float> currentCollections;
        int32_t collectSpeed;
        double tripRangeDrones;
        double tripRangeShips;
        bool includeOrbitCollector;
        double warpEnableDist;
        bool warperNecessary;
        int32_t deliveryDrones;
        int32_t deliveryShips;
    };

    class PlanetTransport
    {
    public:
        PlanetTransport();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t stationCursor;
        int32_t stationCapacity;
        int32_t stationRecycleCursor;
        std::vector<int32_t> stationIndex;
        std::vector<StationComponent> stationPool;
        std::vector<int32_t> stationRecycle;
    };

    class MonsterComponent
    {
    public:
        MonsterComponent();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t entityId;
        float walkSpeed;
        Vector3 point0;
        Vector3 point1;
        Vector3 point2;
        int32_t direction;
        float stopTime;
        float t;
        float stopCurrentTime;
        enum class EMonsterState { Null, Stopped, Wandering };
        EMonsterState monsterState;
        float stepDistance;
    };

    class MonsterSystem
    {
    public:
        MonsterSystem();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t monsterCapacity;
        int32_t monsterCursor;
        int32_t monsterRecycleCursor;
        std::vector<MonsterComponent> monsterPool;
        std::vector<int32_t> monsterRecycle;
    };

    class PlatformSystem
    {
    public:
        PlatformSystem();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t reformDataByteCount;
        std::vector<uint8_t> reformData;
        int32_t reformOffsetsByteCount;
        std::vector<uint32_t> reformOffsets;
    };

    class PlanetFactory
    {
    public:
        PlanetFactory();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t planetId;
        PlanetData planet;
        int32_t entityCapacity;
        int32_t entityCursor;
        int32_t entityRecycleCursor;
        std::vector<EntityData> entityPool;
        std::vector<AnimData> entityAnimPool;
        std::vector<SignData> entitySignPool;
        std::vector<int32_t> entityConnPool;
        std::vector<int32_t> entityRecycle;
        int32_t prebuildCapacity;
        int32_t prebuildCursor;
        int32_t prebuildRecycleCursor;
        std::vector<PrebuildData> prebuildPool;
        std::vector<int32_t> prebuildConnPool;
        std::vector<int32_t> prebuildRecycle;
        int32_t vegeCapacity;
        int32_t vegeCursor;
        int32_t vegeRecycleCursor;
        std::vector<VegeData> vegePool;
        std::vector<int32_t> vegeRecycle;
        int32_t veinCapacity;
        int32_t veinCursor;
        int32_t veinRecycleCursor;
        std::vector<VeinData> veinPool;
        std::vector<int32_t> veinRecycle;
        std::vector<AnimData> veinAnimPool;
        CargoContainer cargoContainer;
        CargoTraffic cargoTraffic;
        FactoryStorage factoryStorage;
        PowerSystem powerSystem;
        FactorySystem factorySystem;
        PlanetTransport transport;
        MonsterSystem monsterSystem;
        PlatformSystem platformSystem;
    };

    class DysonSail
    {
    public:
        DysonSail();
        void parse(std::ifstream& strm);

        float st;
        Vector3 p;
        Vector3 v;
        float gs;
    };

    class DysonSailInfo
    {
    public:
        DysonSailInfo();
        void parse(std::ifstream& strm);

        uint32_t orbit;
        uint32_t node;
        uint32_t kill;
        Vector3 posr;
    };

    class SailOrbit
    {
    public:
        SailOrbit();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        float radius;
        Quaternion rotation;
        Vector3 up;
        int32_t count;
        bool enabled;
    };

    class ExpiryOrder
    {
    public:
        ExpiryOrder();
        void parse(std::ifstream& strm);

        int64_t time;
        int32_t index;
    };

    class AbsorbOrder
    {
    public:
        AbsorbOrder();
        void parse(std::ifstream& strm);

        int64_t time;
        int32_t index;
        int32_t layer;
        int32_t node;
    };

    class SailBullet
    {
    public:
        SailBullet();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        float t;
        float maxt;
        int32_t state;
        Vector3 rBegin;
        Vector3 rEnd;
        Vector3 lBegin;
        Vector3 uEndVel;
        VectorLF3 uBegin;
        VectorLF3 uEnd;
    };

    class DysonSwarm
    {
    public:
        DysonSwarm();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t randSeed;
        int32_t sailCapacity;
        int32_t sailCursor;
        int32_t sailRecycleCursor;
        std::vector<DysonSail> sailPoolForSave;
        std::vector<DysonSailInfo> sailInfos;
        std::vector<int32_t> sailRecycle;
        int32_t orbitCapacity;
        int32_t orbitCursor;
        std::vector<SailOrbit> orbits;
        int32_t numExpiryOrder;
        int32_t expiryCursor;
        int32_t expiryEnding;
        std::vector<ExpiryOrder> expiryOrder;
        int32_t numAbsorbOrder;
        int32_t absorbCursor;
        int32_t absorbEnding;
        std::vector<AbsorbOrder> absorbOrder;
        int32_t bulletCapacity;
        int32_t bulletCursor;
        int32_t bulletRecycleCursor;
        std::vector<SailBullet> bulletPool;
        std::vector<int32_t> bulletRecycle;
    };

    class DysonNode
    {
    public:
        DysonNode();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t protoId;
        int32_t layerId;
        bool use;
        bool reserved;
        Vector3 pos;
        int32_t sp;
        int32_t spMax;
        int32_t spOrdered;
        int32_t cpOrdered;
        int32_t rid;
        int32_t frameTurn;
        int32_t shellTurn;
        int32_t _spReq;
        int32_t _cpReq;
    };

    class DysonFrame
    {
    public:
        DysonFrame();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t protoId;
        int32_t layerId;
        bool reserved;
        int32_t nodeId;
        int32_t nodeId2;
        bool euler;
        int32_t spA;
        int32_t spB;
        int32_t spMax;
    };

    class DysonShell
    {
    public:
        DysonShell();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t protoId;
        int32_t layerId;
        int32_t randSeed;
        int32_t numPolygon;
        std::vector<Vector3> polygon;
        int32_t numDysonNode;
        std::vector<int32_t> nodeId;
        int32_t vertexCount;
        int32_t triangleCount;
        int32_t numVerts;
        std::vector<Vector3> verts;
        int32_t numPqArr;
        std::vector<IntVector2> pqArr;
        int32_t numTris;
        std::vector<int32_t> tris;
        int32_t numVAdjs;
        std::vector<int32_t> vAdjs;
        int32_t numVertAttr;
        std::vector<int32_t> vertAttr;
        int32_t numVertsq;
        std::vector<int32_t> vertsq;
        int32_t numVertsqOffset;
        std::vector<int32_t> vertsqOffset;
        int32_t numNodecps;
        std::vector<int32_t> nodecps;
        int32_t numVertcps;
        std::vector<int32_t> vertcps;
        int32_t vertRecycleArraySize;
        int32_t vertRecycleCursor;
        std::vector<int32_t> vertRecycle;
    };

    class DysonSphereLayer
    {
    public:
        DysonSphereLayer();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        float orbitRadius;
        Quaternion orbitRotation;
        float orbitAngularSpeed;
        float currentAngle;
        Quaternion currentRotation;
        Quaternion nextRotation;
        int32_t gridMode;
        int32_t nodeCapacity;
        int32_t nodeCursor;
        int32_t nodeRecycleCursor;
        std::vector<int32_t> dysonNodeIndex;
        std::vector<DysonNode> nodePool;
        std::vector<int32_t> nodeRecycle;
        int32_t frameCapacity;
        int32_t frameCursor;
        int32_t frameRecycleCursor;
        std::vector<int32_t> dysonFrameIndex;
        std::vector<DysonFrame> framePool;
        std::vector<int32_t> frameRecycle;
        int32_t shellCapacity;
        int32_t shellCursor;
        int32_t shellRecycleCursor;
        std::vector<int32_t> dysonShellIndex;
        std::vector<DysonShell> shellPool;
        std::vector<int32_t> shellRecycle;
    };

    class DysonRocket
    {
    public:
        DysonRocket();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t nodeLayerId;
        int32_t nodeId;
        int32_t planetId;
        float t;
        float uSpeed;
        VectorLF3 uPos;
        Quaternion uRot;
        Vector3 uVel;
        Vector3 launch;
    };

    class DysonNodeRData
    {
    public:
        DysonNodeRData();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t id;
        int32_t layerId;
        Vector3 pos;
        float angularVel;
        Quaternion layerRot;
    };

    class DysonSphere
    {
    public:
        DysonSphere();
        void parse(std::ifstream& strm);

        int32_t version;
        int32_t randSeed;
        DysonSwarm swarm;
        int32_t twelveTwelve;
        int32_t layerCount;
        int32_t numDysonSphereLayer;
        std::vector<int32_t> dysonSphereLayerIndex;
        std::vector<DysonSphereLayer> dysonSphereLayer;
        int32_t rocketCapacity;
        int32_t rocketCursor;
        int32_t rocketRecycleCursor;
        std::vector<DysonRocket> rocketPool;
        std::vector<int32_t> rocketRecycle;
        int32_t autoNodeCount;
        int32_t numAutoNodes;
        std::vector<int32_t> autoNodeIncludedFlag;
        std::vector<int32_t> layerId;
        std::vector<int32_t> nodeId;
        int32_t nrdCapacity;
        int32_t nrdCursor;
        int32_t nrdRecycleCursor;
        std::vector<DysonNodeRData> nrdPool;
        std::vector<int32_t> nrdRecycle;
    };

    class GameData
    {
    public:
        GameData();
        void parse(std::ifstream& strm);

        int32_t version;
        std::string gameName;
        GameDesc gameDesc;
        int64_t gameTick;
        GamePrefsData preferences;
        GameHistoryData history;
        bool hidePlayerModel;
        bool disableController;
        GameStatData statistics;
        int32_t planetId;
        Player mainPlayer;
        int32_t factoryCount;
        GalacticTransport galacticTransport;
        std::vector<PlanetFactory> factories;
        int32_t galaxyStarCount;
        std::vector<int32_t> dysonSphereIndex;
        std::vector<DysonSphere> dysonSpheres;
    };

    class GameSave
    {
    public:
        GameSave();
        void parse(std::ifstream& strm);

        int64_t fileStreamLength;
        int32_t saveFileFormatNumber;
        int32_t majorGameVersion;
        int32_t minorGameVersion;
        int32_t releaseGameVersion;
        int64_t gameTick;
        int64_t nowTicks;
        int32_t sizeOfPngFile;
        std::vector<uint8_t> screenShotPngFile;
        GameData data;
    };

    template<typename CHAR>
    DysonSphereParser(const CHAR* const filename);

    template<typename TYPE>
    static void read(std::ifstream& strm, TYPE& value)
    {
        strm.read(reinterpret_cast<char*>(&value), sizeof(value));
    }

    static void read(std::ifstream& strm, bool& value)
    {
        uint8_t raw = 0;
        strm.read(reinterpret_cast<char*>(&raw), 1);
        value = raw ? true : false;
    }

    static void read(std::ifstream& strm, std::string& value)
    {
        uint8_t length = 0;
        read(strm, length);
        char* string = new char[length + 1];
        strm.read(string, length);
        string[length] = '\0';
        value = string;
        delete[] string;
    }

    template<typename TYPE>
    static void read(std::ifstream& strm, std::vector<TYPE>& vect, const int32_t size)
    {
        vect.resize(size);
        for (auto it = vect.begin(); it != vect.end(); ++it)
            read(strm, *it);
    }

    template<typename TYPE1, typename TYPE2>
    static void read(std::ifstream& strm, std::vector<TYPE1>& vect1, std::vector<TYPE2>& vect2, const int32_t size)
    {
        vect1.resize(size);
        vect2.resize(size);
        auto it1 = vect1.begin();
        auto it2 = vect2.begin();
        for (; it1 != vect1.end(); ++it1, ++it2)
        {
            read(strm, *it1);
            read(strm, *it2);
        }
    }

    template<typename TYPE1, typename TYPE2, typename TYPE3>
    static void read(std::ifstream& strm, std::vector<TYPE1>& vect1, std::vector<TYPE2>& vect2, std::vector<TYPE3>& vect3, const int32_t size)
    {
        vect1.resize(size);
        vect2.resize(size);
        vect3.resize(size);
        auto it1 = vect1.begin();
        auto it2 = vect2.begin();
        auto it3 = vect3.begin();
        for (; it1 != vect1.end(); ++it1, ++it2, ++it3)
        {
            read(strm, *it1);
            read(strm, *it2);
            read(strm, *it3);
        }
    }

    template<typename TYPE1, typename TYPE2>
    static void read(std::ifstream& strm, std::map<TYPE1, TYPE2>& m, const int32_t size)
    {
        for (int32_t i = 0; i < size; ++i)
        {
            int32_t key = 0;
            int32_t value = 0;
            read(strm, key);
            read(strm, value);
            m[key] = value;
        }
    }

    template<typename TYPE, typename CLASS>
    static void readi(std::ifstream& strm, std::vector<TYPE>& iVect, std::vector<CLASS>& cVect, const int32_t size)
    {
        for (int i = 0; i < size; ++i)
        {
            int32_t index = 0;
            read(strm, index);
            if (index != 0)
            {
                /*if (index != i)
                {
                    assert(false);
                    throw std::exception("Index mismatch");
                }*/
                iVect.push_back(index);
                cVect.push_back(CLASS());
                cVect.rbegin()->parse(strm);
            }
        }
    }

    template<typename CLASS>
    static void readv(std::ifstream& strm, std::vector<CLASS>& instance, const int32_t size)
    {
        if (size < 0)
            return;
        instance.resize(size);
        for (auto it = instance.begin(); it != instance.end(); ++it)
            it->parse(strm);
    }

    template<typename CLASS1, typename CLASS2>
    static void readv(std::ifstream& strm, std::vector<CLASS1>& instance1, std::vector<CLASS2>& instance2, const int32_t size)
    {
        instance1.resize(size);
        instance2.resize(size);
        for (int32_t i = 0; i < size; ++i)
        {
            instance1[i].parse(strm);
            instance2[i].parse(strm);
        }
    }

    template<typename ENUM, typename TYPE>
    static void read(std::ifstream& strm, ENUM& e)
    {
        TYPE temp = 0;
        strm.read(reinterpret_cast<char*>(&temp), sizeof(temp));
        e = static_cast<ENUM>(temp);
    }

    GameSave gameSave;
    bool m_readSuccessFlag;
    std::string m_failureDescription;
};
