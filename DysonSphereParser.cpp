//
// Copyright (c) 2021, Aaron Shumate
// All rights reserved.
//
// This source code is licensed under the BSD-style license found in the
// LICENSE.txt file in the root directory of this source tree. 
//
// Dyson Sphere Program is developed by Youthcat Studio and published by Gamera Game.

#include <assert.h>
#include <iostream>
#include "DysonSphereParser.h"

DysonSphereParser::IntVector2::IntVector2() :
	x(0),
	y(0)
{
}

void DysonSphereParser::IntVector2::parse(std::ifstream& strm)
{
	read(strm, x);
	read(strm, y);
}

DysonSphereParser::Vector3::Vector3() :
	x(0),
	y(0),
	z(0)
{
}

void DysonSphereParser::Vector3::parse(std::ifstream& strm)
{
	read(strm, x);
	read(strm, y);
	read(strm, z);
}

DysonSphereParser::VectorLF3::VectorLF3() :
	x(0),
	y(0),
	z(0)
{
}

void DysonSphereParser::VectorLF3::parse(std::ifstream& strm)
{
	read(strm, x);
	read(strm, y);
	read(strm, z);
}

DysonSphereParser::Quaternion::Quaternion() :
	x(0),
	y(0),
	z(0),
	w(0)
{
}

void DysonSphereParser::Quaternion::parse(std::ifstream& strm)
{
	read(strm, x);
	read(strm, y);
	read(strm, z);
	read(strm, w);
}

DysonSphereParser::GameDesc::GameDesc() :
	version(0),
	galaxyAlgo(0),
	galaxySeed(0),
	starCount(0),
	playerProto(0),
	resourceMultiplier(0),
	numThemeIds(0)
{
}

void DysonSphereParser::GameDesc::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 2)
	{
		assert(false);
		throw std::exception("Unexpected GameDesc version");
	}
	read(strm, galaxyAlgo);
	read(strm, galaxySeed);
	read(strm, starCount);
	read(strm, playerProto);
	read(strm, resourceMultiplier);
	read(strm, numThemeIds);
	read(strm, themeIds, numThemeIds);
}

DysonSphereParser::GamePrefsData::GamePrefsData() :
	version(0),
	reformCursorSize(0),
	numReplicatorMultipliers(0),
	detailPower(false),
	detailVein(false),
	detailSpaceGuide(false),
	detailSign(false),
	detailIcon(false),
	numTutorialShowing(0)
{
}

void DysonSphereParser::GamePrefsData::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 2)
	{
		assert(false);
		throw std::exception("Unexpected GamePrefsData version");
	}
	cameraUPos.parse(strm);
	cameraURot.parse(strm);
	read(strm, reformCursorSize);
	read(strm, numReplicatorMultipliers);
	read(strm, replicatorMultipliers, numReplicatorMultipliers);
	read(strm, detailPower);
	read(strm, detailVein);
	read(strm, detailSpaceGuide);
	read(strm, detailSign);
	read(strm, detailIcon);
	read(strm, numTutorialShowing);
	read(strm, tutorialShowing, numTutorialShowing);
}

DysonSphereParser::TechState::TechState() :
	techProtoIndex(0),
	unlocked(false),
	curLevel(0),
	maxLevel(0),
	hashUploaded(0),
	hashNeeded(0)
{
}

void DysonSphereParser::TechState::parse(std::ifstream& strm)
{
	read(strm, techProtoIndex);
	read(strm, unlocked);
	read(strm, curLevel);
	read(strm, maxLevel);
	read(strm, hashUploaded);
	read(strm, hashNeeded);
}

DysonSphereParser::GameHistoryData::GameHistoryData() :
	version(0),
	numRecipeUnlocked(0),
	numTutorialUnlocked(0),
	numFeatureKeys(0),
	numTechState(0),
	autoManageLabItems(false),
	currentTech(0),
	numTechQueue(0),
	universeObserveLevel(0),
	solarSailLife(0.0),
	solarEnergyLossRate(0.0),
	useIonLayer(false),
	inserterStackCount(0),
	logisticDroneSpeed(0.0),
	logisticDroneSpeedScale(0.0),
	logisticDroneCarries(0),
	logisticShipSailSpeed(0.0),
	logisticShipWarpSpeed(0.0),
	logisticShipSpeedScale(0.0),
	logisticShipWarpDrive(false),
	logisticShipCarries(0),
	miningCostRate(0.0),
	miningSpeedScale(0.0),
	storageLevel(0),
	labLevel(0),
	techSpeed(0),
	dysonNodeLatitude(0.0),
	universeMatrixPointUploaded(0),
	missionAccomplished(false)
{
}

void DysonSphereParser::GameHistoryData::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 2)
	{
		assert(false);
		throw std::exception("Unexpected GameHistoryData version");
	}
	read(strm, numRecipeUnlocked);
	read(strm, recipeUnlocked, numRecipeUnlocked);
	read(strm, numTutorialUnlocked);
	read(strm, tutorialUnlocked, numTutorialUnlocked);
	read(strm, numFeatureKeys);
	read(strm, featureKeys, numFeatureKeys);
	read(strm, numTechState);
	readv(strm, techStates, numTechState);
	read(strm, autoManageLabItems);
	read(strm, currentTech);
	read(strm, numTechQueue);
	read(strm, techQueue, numTechQueue);
	read(strm, universeObserveLevel);
	read(strm, solarSailLife);
	read(strm, solarEnergyLossRate);
	read(strm, useIonLayer);
	read(strm, inserterStackCount);
	read(strm, logisticDroneSpeed);
	read(strm, logisticDroneSpeedScale);
	read(strm, logisticDroneCarries);
	read(strm, logisticShipSailSpeed);
	read(strm, logisticShipWarpSpeed);
	read(strm, logisticShipSpeedScale);
	read(strm, logisticShipWarpDrive);
	read(strm, logisticShipCarries);
	read(strm, miningCostRate);
	read(strm, miningSpeedScale);
	read(strm, storageLevel);
	read(strm, labLevel);
	read(strm, techSpeed);
	read(strm, dysonNodeLatitude);
	read(strm, universeMatrixPointUploaded);
	read(strm, missionAccomplished);
}

DysonSphereParser::ProductStat::ProductStat() :
	version(0),
	numCount(0),
	numCursor(0),
	numTotal(0),
	itemId(0)
{
}

void DysonSphereParser::ProductStat::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected ProductStat version");
	}
	read(strm, numCount);
	read(strm, count, numCount);
	read(strm, numCursor);
	read(strm, cursor, numCursor);
	read(strm, numTotal);
	read(strm, total, numTotal);
	read(strm, itemId);
}

DysonSphereParser::PowerStat::PowerStat() :
	version(0),
	numEnergy(0),
	numCursor(0),
	numTotal(0),
	itemId(0)
{
}

void DysonSphereParser::PowerStat::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected PowerStat version");
	}
	read(strm, numEnergy);
	read(strm, energy, numEnergy);
	read(strm, numCursor);
	read(strm, cursor, numCursor);
	read(strm, numTotal);
	read(strm, total, numTotal);
}

DysonSphereParser::FactoryProductionStat::FactoryProductionStat() :
	version(0),
	productCapacity(0),
	productCursor(0),
	numPowerPool(0),
	numProductIndices(0),
	energyConsumption(0)
{
}

void DysonSphereParser::FactoryProductionStat::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 1)
	{
		assert(false);
		throw std::exception("Unexpected FactoryProductionStat version");
	}
	read(strm, productCapacity);
	read(strm, productCursor);
	readv(strm, productPool, productCursor - 1);
	read(strm, numPowerPool);
	if (numPowerPool > 5)
	{
		assert(false);
		throw std::exception("Unexpected FactoryProductionStat numPowerPool");
	}
	readv(strm, powerPool, numPowerPool);
	read(strm, numProductIndices);
	read(strm, productIndices, numProductIndices);
	read(strm, energyConsumption);
}

DysonSphereParser::ProductionStatistics::ProductionStatistics() :
	version(0),
	numFactoryStatPool(0),
	numFirstCreateIds(0),
	numFavoriteIds(0)
{
}

void DysonSphereParser::ProductionStatistics::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected ProductionStatistics version");
	}
	read(strm, numFactoryStatPool);
	readv(strm, factoryStatPool, numFactoryStatPool);
	read(strm, numFirstCreateIds);
	read(strm, firstCreateIds, numFirstCreateIds);
	read(strm, numFavoriteIds);
	read(strm, favoriteIds, numFavoriteIds);
}

DysonSphereParser::GameStatData::GameStatData() :
	version(0),
	numTechHashedHistory(0)
{
}

void DysonSphereParser::GameStatData::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected GameStatData version");
	}
	read(strm, numTechHashedHistory);
	read(strm, techHashedHistory, numTechHashedHistory);
	production.parse(strm);
}

DysonSphereParser::StorageComponent::StorageComponent() :
	version(0),
	id(0),
	entityId(0),
	previous(0),
	next(0),
	bottom(0),
	top(0),
	type(DysonSphereParser::StorageComponent::EStorageType::Default),
	gridSize(0),
	bans(0)
{
}

void DysonSphereParser::StorageComponent::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 1)
	{
		assert(false);
		throw std::exception("Unexpected StorageComponent version");
	}
	read(strm, id);
	read(strm, entityId);
	read(strm, previous);
	read(strm, next);
	read(strm, bottom);
	read(strm, top);
	read<DysonSphereParser::StorageComponent::EStorageType, int32_t>(strm, type);
	read(strm, gridSize);
	read(strm, bans);
	grids.resize(gridSize);
	for (auto it = grids.begin(); it != grids.end(); ++it)
	{
		read(strm, it->itemId);
		read(strm, it->filter);
		read(strm, it->count);
		read(strm, it->stackSize);
	}
}

DysonSphereParser::ForgeTask::ForgeTask() :
	version(0),
	recipeId(0),
	count(0),
	tick(0),
	tickSpend(0),
	numItem(0),
	numProduct(0),
	parentTaskIndex(0)
{
}

void DysonSphereParser::ForgeTask::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected ForgeTask version");
	}
	read(strm, recipeId);
	read(strm, count);
	read(strm, tick);
	read(strm, tickSpend);
	read(strm, numItem);
	read(strm, numProduct);
	read(strm, itemIds, itemCounts, served, numItem);
	read(strm, productIds, productCounts, produced, numProduct);
	read(strm, parentTaskIndex);
}

DysonSphereParser::MechaForge::MechaForge() :
	version(0),
	numTasks(0)
{
}

void DysonSphereParser::MechaForge::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected MechaForge version");
	}
	read(strm, numTasks);
	readv(strm, tasks, numTasks);
}

DysonSphereParser::MechaLab::MechaLab() :
	version(0),
	numItemPoints(0)
{
}

void DysonSphereParser::MechaLab::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected MechaLab version");
	}
	read(strm, numItemPoints);
	read(strm, itemPoints, numItemPoints);
}

DysonSphereParser::MechaDrone::MechaDrone() :
	version(0),
	stage(0),
	speed(0.0),
	movement(0),
	targetObject(0),
	progress(0.0)
{
}

void DysonSphereParser::MechaDrone::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected MechaDrone version");
	}
	read(strm, stage);
	position.parse(strm);
	target.parse(strm);
	forward.parse(strm);
	read(strm, speed);
	read(strm, movement);
	read(strm, targetObject);
	read(strm, progress);
	initialVector.parse(strm);
}

DysonSphereParser::Mecha::Mecha() :
	version(0),
	coreEnergyCap(0.0),
	coreEnergy(0.0),
	corePowerGen(0.0),
	reactorPowerGen(0.0),
	reactorEnergy(0.0),
	reactorItemId(0),
	walkPower(0.0),
	jumpEnergy(0.0),
	thrustPowerPerAcc(0.0),
	warpKeepingPowerPerSpeed(0.0),
	warpStartPowerPerSpeed(0.0),
	miningPower(0.0),
	replicatePower(0.0),
	researchPower(0.0),
	droneEjectEnergy(0.0),
	droneEnergyPerMeter(0.0),
	coreLevel(0),
	thrusterLevel(0),
	miningSpeed(0.0),
	replicateSpeed(0.0),
	walkSpeed(0.0),
	jumpSpeed(0.0),
	maxSailSpeed(0.0),
	maxWarpSpeed(0.0),
	buildArea(0.0),
	droneCount(0),
	droneSpeed(0.0),
	droneMovement(0)
{
}

void DysonSphereParser::Mecha::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected Mecha version");
	}
	read(strm, coreEnergyCap);
	read(strm, coreEnergy);
	read(strm, corePowerGen);
	read(strm, reactorPowerGen);
	read(strm, reactorEnergy);
	read(strm, reactorItemId);
	reactorStorage.parse(strm);
	warpStorage.parse(strm);
	read(strm, walkPower);
	read(strm, jumpEnergy);
	read(strm, thrustPowerPerAcc);
	read(strm, warpKeepingPowerPerSpeed);
	read(strm, warpStartPowerPerSpeed);
	read(strm, miningPower);
	read(strm, replicatePower);
	read(strm, researchPower);
	read(strm, droneEjectEnergy);
	read(strm, droneEnergyPerMeter);
	read(strm, coreLevel);
	read(strm, thrusterLevel);
	read(strm, miningSpeed);
	read(strm, replicateSpeed);
	read(strm, walkSpeed);
	read(strm, jumpSpeed);
	read(strm, maxSailSpeed);
	read(strm, maxWarpSpeed);
	read(strm, buildArea);
	forge.parse(strm);
	lab.parse(strm);
	read(strm, droneCount);
	read(strm, droneSpeed);
	read(strm, droneMovement);
	readv(strm, drones, droneCount);
}

DysonSphereParser::PlayerNavigation::PlayerNavigation() :
	version(0),
	navigating(0),
	naviAstroId(0),
	useFly(0),
	useSail(0),
	useWarp(0),
	stage(DysonSphereParser::PlayerNavigation::ENaviStage::None),
	flyThreshold(0.0),
	sailThreshold(0.0),
	warpThreshold(0.0),
	maxSailSpeed(0.0)
{
}

void DysonSphereParser::PlayerNavigation::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected PlayerNavigation version");
	}
	read(strm, navigating);
	read(strm, naviAstroId);
	naviTarget.parse(strm);
	read(strm, useFly);
	read(strm, useSail);
	read(strm, useWarp);
	read<DysonSphereParser::PlayerNavigation::ENaviStage, int32_t>(strm, stage);
	read(strm, flyThreshold);
	read(strm, sailThreshold);
	read(strm, warpThreshold);
	read(strm, maxSailSpeed);
}

DysonSphereParser::Player::Player() :
	version(0),
	planetId(0),
	movementState(DysonSphereParser::Player::EMovementState::Walk),
	warpState(0.0),
	warpCommand(false),
	inhandItemId(0),
	inhandItemCount(0),
	sandCount(0)
{
}

void DysonSphereParser::Player::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 1)
	{
		assert(false);
		throw std::exception("Unexpected Player version");
	}
	read(strm, planetId);
	position.parse(strm);
	uPosition.parse(strm);
	uRotation.parse(strm);
	read<DysonSphereParser::Player::EMovementState, int32_t>(strm, movementState);
	read(strm, warpState);
	read(strm, warpCommand);
	uVelocity.parse(strm);
	read(strm, inhandItemId);
	read(strm, inhandItemCount);
	mecha.parse(strm);
	package.parse(strm);
	navigation.parse(strm);
	read(strm, sandCount);
}

DysonSphereParser::GalacticTransport::GalacticTransport() :
	version(0)
{
}

void DysonSphereParser::GalacticTransport::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected GalacticTransport version");
	}
}

DysonSphereParser::VeinGroup::VeinGroup() :
	type(DysonSphereParser::EVeinType::None),
	count(0),
	amount(0)
{
}

void DysonSphereParser::VeinGroup::parse(std::ifstream& strm)
{
	read<DysonSphereParser::EVeinType, int32_t>(strm, type);
	pos.parse(strm);
	read(strm, count);
	read(strm, amount);
}

DysonSphereParser::PlanetData::PlanetData() :
	modDataByteCount(0),
	numVeinAmounts(0),
	numVeinGroups(0)
{
}

void DysonSphereParser::PlanetData::parse(std::ifstream& strm)
{
	read(strm, modDataByteCount);
	read(strm, modData, modDataByteCount);
	read(strm, numVeinAmounts);
	read(strm, veinAmounts, numVeinAmounts);
	read(strm, numVeinGroups);
	readv(strm, veinGroups, numVeinGroups);
}

DysonSphereParser::EntityData::EntityData() :
	version(0),
	id(0),
	protoId(0),
	modelIndex(0),
	beltId(0),
	splitterId(0),
	storageId(0),
	tankId(0),
	minerId(0),
	inserterId(0),
	assemblerId(0),
	fractionateId(0),
	ejectorId(0),
	siloId(0),
	labId(0),
	stationId(0),
	powerNodeId(0),
	powerGenId(0),
	powerConId(0),
	powerAccId(0),
	powerExcId(0),
	monsterId(0)
{
}

void DysonSphereParser::EntityData::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected EntityData version");
	}
	read(strm, id);
	read(strm, protoId);
	read(strm, modelIndex);
	pos.parse(strm);
	rot.parse(strm);
	read(strm, beltId);
	read(strm, splitterId);
	read(strm, storageId);
	read(strm, tankId);
	read(strm, minerId);
	read(strm, inserterId);
	read(strm, assemblerId);
	read(strm, fractionateId);
	read(strm, ejectorId);
	read(strm, siloId);
	read(strm, labId);
	read(strm, stationId);
	read(strm, powerNodeId);
	read(strm, powerGenId);
	read(strm, powerConId);
	read(strm, powerAccId);
	read(strm, powerExcId);
	read(strm, monsterId);
}

DysonSphereParser::AnimData::AnimData() :
	time(0.0),
	prepare_length(0.0),
	working_length(0.0),
	state(0),
	power(0.0)
{
}

void DysonSphereParser::AnimData::parse(std::ifstream& strm)
{
	read(strm, time);
	read(strm, prepare_length);
	read(strm, working_length);
	read(strm, state);
	read(strm, power);
}

DysonSphereParser::SignData::SignData() :
	signType(0),
	iconType(0),
	iconId0(0),
	iconId1(0),
	iconId2(0),
	iconId3(0),
	count0(0.0),
	count1(0.0),
	count2(0.0),
	count3(0.0),
	x(0.0),
	y(0.0),
	z(0.0),
	w(0.0)
{
}

void DysonSphereParser::SignData::parse(std::ifstream& strm)
{
	read(strm, signType);
	read(strm, iconType);
	read(strm, iconId0);
	read(strm, iconId1);
	read(strm, iconId2);
	read(strm, iconId3);
	read(strm, count0);
	read(strm, count1);
	read(strm, count2);
	read(strm, count3);
	read(strm, x);
	read(strm, y);
	read(strm, z);
	read(strm, w);
}

DysonSphereParser::PrebuildData::PrebuildData() :
	version(0),
	id(0),
	protoId(0),
	modelIndex(0),
	upEntity(0),
	pickOffset(0),
	insertOffset(0),
	recipeId(0),
	filterId(0),
	refCount(0)
{
}

void DysonSphereParser::PrebuildData::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected PrebuildData version");
	}
	read(strm, id);
	read(strm, protoId);
	read(strm, modelIndex);
	pos.parse(strm);
	rot.parse(strm);
	pos2.parse(strm);
	rot2.parse(strm);
	read(strm, upEntity);
	read(strm, pickOffset);
	read(strm, insertOffset);
	read(strm, recipeId);
	read(strm, filterId);
	read(strm, refCount);
	read(strm, refArr, refCount);
}

DysonSphereParser::VegeData::VegeData() :
	version(0),
	id(0),
	protoId(0),
	modelIndex(0),
	hp(0)
{
}

void DysonSphereParser::VegeData::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected VegeData version");
	}
	read(strm, id);
	read(strm, protoId);
	read(strm, modelIndex);
	read(strm, hp);
	pos.parse(strm);
	rot.parse(strm);
	scl.parse(strm);
}

DysonSphereParser::VeinData::VeinData() :
	version(0),
	id(0),
	type(DysonSphereParser::EVeinType::None),
	modelIndex(0),
	groupIndex(0),
	amount(0),
	productId(0),
	minerCount(0),
	minerId0(0),
	minerId1(0),
	minerId2(0),
	minerId3(0)
{
}

void DysonSphereParser::VeinData::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected VeinData version");
	}
	read(strm, id);
	read<DysonSphereParser::EVeinType, int16_t>(strm, type);
	read(strm, modelIndex);
	read(strm, groupIndex);
	read(strm, amount);
	read(strm, productId);
	pos.parse(strm);
	read(strm, minerCount);
	read(strm, minerId0);
	read(strm, minerId1);
	read(strm, minerId2);
	read(strm, minerId3);
}

DysonSphereParser::Cargo::Cargo() :
	item(0)
{
}

void DysonSphereParser::Cargo::parse(std::ifstream& strm)
{
	read(strm, item);
	position.parse(strm);
	rotation.parse(strm);
}

DysonSphereParser::CargoContainer::CargoContainer() :
	version(0),
	poolCapacity(0),
	cursor(0),
	recycleBegin(0),
	recycleEnd(0)
{
}

void DysonSphereParser::CargoContainer::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected CargoContainer version");
	}
	read(strm, poolCapacity);
	read(strm, cursor);
	read(strm, recycleBegin);
	read(strm, recycleEnd);
	readv(strm, cargoPool, cursor);
	read(strm, recycleIds, poolCapacity);
}

DysonSphereParser::BeltComponent::BeltComponent() :
	version(0),
	id(0),
	entityId(0),
	speed(0),
	segPathId(0),
	segIndex(0),
	segPivotOffset(0),
	segLength(0),
	outputId(0),
	backInputId(0),
	leftInputId(0),
	rightInputId(0)
{
}

void DysonSphereParser::BeltComponent::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected BeltComponent version");
	}
	read(strm, id);
	read(strm, entityId);
	read(strm, speed);
	read(strm, segPathId);
	read(strm, segIndex);
	read(strm, segPivotOffset);
	read(strm, segLength);
	read(strm, outputId);
	read(strm, backInputId);
	read(strm, leftInputId);
	read(strm, rightInputId);
}

DysonSphereParser::SplitterComponent::SplitterComponent() :
	version(0),
	id(0),
	entityId(0),
	beltA(0),
	beltB(0),
	beltC(0),
	beltD(0),
	input0(0),
	input1(0),
	input2(0),
	input3(0),
	output0(0),
	output1(0),
	output2(0),
	output3(0),
	inPriority(false),
	outPriority(false),
	outFilter(0)
{
}

void DysonSphereParser::SplitterComponent::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected SplitterComponent version");
	}
	read(strm, id);
	read(strm, entityId);
	read(strm, beltA);
	read(strm, beltB);
	read(strm, beltC);
	read(strm, beltD);
	read(strm, input0);
	read(strm, input1);
	read(strm, input2);
	read(strm, input3);
	read(strm, output0);
	read(strm, output1);
	read(strm, output2);
	read(strm, output3);
	read(strm, inPriority);
	read(strm, outPriority);
	read(strm, outFilter);
}

DysonSphereParser::CargoPath::CargoPath() :
	version(0),
	id(0),
	capacity(0),
	bufferLength(0),
	chunkCapacity(0),
	chunkCount(0),
	updateLen(0),
	closed(false),
	outputPathIdForImport(0),
	outputIndex(0),
	numBelts(0),
	numInputPaths(0)
{
}

void DysonSphereParser::CargoPath::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected CargoPath version");
	}
	read(strm, id);
	read(strm, capacity);
	read(strm, bufferLength);
	read(strm, chunkCapacity);
	read(strm, chunkCount);
	read(strm, updateLen);
	read(strm, closed);
	read(strm, outputPathIdForImport);
	read(strm, outputIndex);
	read(strm, numBelts);
	read(strm, numInputPaths);

	buffer.resize(bufferLength);
	strm.read(reinterpret_cast<char*>(buffer.data()), bufferLength);

	read(strm, chunks, chunkCount * 3);
	readv(strm, pointPos, pointRot, bufferLength);
	read(strm, belts, numBelts);
	read(strm, inputPaths, numInputPaths);
}

DysonSphereParser::CargoTraffic::CargoTraffic() :
	version(0),
	beltCursor(0),
	beltCapacity(0),
	beltRecycleCursor(0),
	splitterCursor(0),
	splitterCapacity(0),
	splitterRecycleCursor(0),
	pathCursor(0),
	pathCapacity(0),
	pathRecycleCursor(0)
{
}

void DysonSphereParser::CargoTraffic::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected CargoTraffic version");
	}
	read(strm, beltCursor);
	read(strm, beltCapacity);
	read(strm, beltRecycleCursor);
	read(strm, splitterCursor);
	read(strm, splitterCapacity);
	read(strm, splitterRecycleCursor);
	read(strm, pathCursor);
	read(strm, pathCapacity);
	read(strm, pathRecycleCursor);
	readv(strm, beltPool, beltCursor - 1);
	read(strm, beltRecycle, beltRecycleCursor);
	readv(strm, splitterPool, splitterCursor - 1);
	read(strm, splitterRecycle, splitterRecycleCursor);
	readi(strm, cargoPathIndex, pathPool, pathCursor - 1);
	read(strm, pathRecycle, pathRecycleCursor);
}

DysonSphereParser::TankComponent::TankComponent() :
	version(0),
	id(0),
	entityId(0),
	lastTankId(0),
	nextTankId(0),
	belt0(0),
	belt1(0),
	belt2(0),
	belt3(0),
	isOutput0(false),
	isOutput1(false),
	isOutput2(false),
	isOutput3(false),
	fluidStorageCount(0),
	currentCount(0),
	fluidId(0),
	outputSwitch(false),
	inputSwitch(false),
	isBottom(false)
{
}

void DysonSphereParser::TankComponent::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected TankComponent version");
	}
	read(strm, id);
	read(strm, entityId);
	read(strm, lastTankId);
	read(strm, nextTankId);
	read(strm, belt0);
	read(strm, belt1);
	read(strm, belt2);
	read(strm, belt3);
	read(strm, isOutput0);
	read(strm, isOutput1);
	read(strm, isOutput2);
	read(strm, isOutput3);
	read(strm, fluidStorageCount);
	read(strm, currentCount);
	read(strm, fluidId);
	read(strm, outputSwitch);
	read(strm, inputSwitch);
	read(strm, isBottom);
}

DysonSphereParser::FactoryStorage::FactoryStorage() :
	version(0),
	storageCursor(0),
	storageCapacity(0),
	storageRecycleCursor(0),
	tankCapacity(0),
	tankCursor(0),
	tankRecycleCursor(0)
{
}

void DysonSphereParser::FactoryStorage::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected FactoryStorage version");
	}
	read(strm, storageCursor);
	read(strm, storageCapacity);
	read(strm, storageRecycleCursor);
	for (int32_t i = 0; i < storageCursor - 1; ++i)
	{
		int32_t index = 0;
		read(strm, index);
		if (index != 0)
		{
			storagePoolIndex.push_back(index);
			storagePoolSize.push_back(0);
			read(strm, *storagePoolSize.rbegin());
			storagePool.push_back(StorageComponent());
			storagePool.rbegin()->parse(strm);
		}
	}
	read(strm, storageRecycle, storageRecycleCursor);
	read(strm, tankCapacity);
	read(strm, tankCursor);
	read(strm, tankRecycleCursor);
	readv(strm, tankPool, tankCursor - 1);
	read(strm, tankRecycle, tankRecycleCursor);
}

DysonSphereParser::PowerGeneratorComponent::PowerGeneratorComponent() :
	version(0),
	id(0),
	entityId(0),
	networkId(0),
	photovoltaic(false),
	wind(false),
	gamma(false),
	genEnergyPerTick(0),
	useFuelPerTick(0),
	fuelMask(0),
	fuelEnergy(0),
	curFuelId(0),
	fuelId(0),
	fuelCount(0),
	fuelHeat(0),
	catalystId(0),
	catalystPoint(0),
	productId(0),
	productCount(0.0),
	productHeat(0),
	warmup(0.0),
	ionEnhance(0.0),
	x(0.0),
	y(0.0),
	z(0.0)
{
}

void DysonSphereParser::PowerGeneratorComponent::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected PowerGeneratorComponent version");
	}
	read(strm, id);
	read(strm, entityId);
	read(strm, networkId);
	read(strm, photovoltaic);
	read(strm, wind);
	read(strm, gamma);
	read(strm, genEnergyPerTick);
	read(strm, useFuelPerTick);
	read(strm, fuelMask);
	read(strm, fuelEnergy);
	read(strm, curFuelId);
	read(strm, fuelId);
	read(strm, fuelCount);
	read(strm, fuelHeat);
	read(strm, catalystId);
	read(strm, catalystPoint);
	read(strm, productId);
	read(strm, productCount);
	read(strm, productHeat);
	read(strm, warmup);
	read(strm, ionEnhance);
	read(strm, x);
	read(strm, y);
	read(strm, z);
}

DysonSphereParser::PowerNodeComponent::PowerNodeComponent() :
	version(0),
	id(0),
	entityId(0),
	networkId(0),
	isCharger(false),
	workEnergyPerTick(0),
	idleEnergyPerTick(0),
	requiredEnergy(0),
	connectDistance(0.0),
	coverRadius(0.0)
{
}

void DysonSphereParser::PowerNodeComponent::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected PowerNodeComponent version");
	}
	read(strm, id);
	read(strm, entityId);
	read(strm, networkId);
	read(strm, isCharger);
	read(strm, workEnergyPerTick);
	read(strm, idleEnergyPerTick);
	read(strm, requiredEnergy);
	powerPoint.parse(strm);
	read(strm, connectDistance);
	read(strm, coverRadius);
}

DysonSphereParser::PowerConsumerComponent::PowerConsumerComponent() :
	version(0),
	id(0),
	entityId(0),
	networkId(0),
	requiredEnergy(0),
	servedEnergy(0),
	workEnergyPerTick(0),
	idleEnergyPerTick(0)
{
}

void DysonSphereParser::PowerConsumerComponent::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected PowerConsumerComponent version");
	}
	read(strm, id);
	read(strm, entityId);
	read(strm, networkId);
	plugPos.parse(strm);
	read(strm, requiredEnergy);
	read(strm, servedEnergy);
	read(strm, workEnergyPerTick);
	read(strm, idleEnergyPerTick);
}

DysonSphereParser::PowerAccumulatorComponent::PowerAccumulatorComponent() :
	version(0),
	id(0),
	entityId(0),
	networkId(0),
	inputEnergyPerTick(0),
	outputEnergyPerTick(0),
	curEnergy(0),
	maxEnergy(0)
{
}

void DysonSphereParser::PowerAccumulatorComponent::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected PowerAccumulatorComponent version");
	}
	read(strm, id);
	read(strm, entityId);
	read(strm, networkId);
	read(strm, inputEnergyPerTick);
	read(strm, outputEnergyPerTick);
	read(strm, curEnergy);
	read(strm, maxEnergy);
}

DysonSphereParser::PowerExchangerComponent::PowerExchangerComponent() :
	version(0),
	id(0),
	entityId(0),
	networkId(0),
	emptyCount(0),
	fullCount(0),
	targetState(0.0),
	state(0.0),
	energyPerTick(0),
	curPoolEnergy(0),
	poolMaxEnergy(0),
	emptyId(0),
	fullId(0),
	belt0(0),
	belt1(0),
	belt2(0),
	belt3(0),
	isOutput0(false),
	isOutput1(false),
	isOutput2(false),
	isOutput3(false),
	outputSlot(0),
	inputSlot(0),
	outputRectify(0),
	inputRectify(0)
{
}

void DysonSphereParser::PowerExchangerComponent::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 1)
	{
		assert(false);
		throw std::exception("Unexpected PowerExchangerComponent version");
	}
	read(strm, id);
	read(strm, entityId);
	read(strm, networkId);
	read(strm, emptyCount);
	read(strm, fullCount);
	read(strm, targetState);
	read(strm, state);
	read(strm, energyPerTick);
	read(strm, curPoolEnergy);
	read(strm, poolMaxEnergy);
	read(strm, emptyId);
	read(strm, fullId);
	read(strm, belt0);
	read(strm, belt1);
	read(strm, belt2);
	read(strm, belt3);
	read(strm, isOutput0);
	read(strm, isOutput1);
	read(strm, isOutput2);
	read(strm, isOutput3);
	read(strm, outputSlot);
	read(strm, inputSlot);
	read(strm, outputRectify);
	read(strm, inputRectify);
}

DysonSphereParser::PowerNetworkStructures_Node::PowerNetworkStructures_Node() :
	version(0),
	id(0),
	x(0.0),
	y(0.0),
	z(0.0),
	connDistance2(0.0),
	coverRadius2(0.0),
	genId(0),
	accId(0),
	excId(0),
	numConnIdsForLoad(0),
	numLineIdsForLoad(0),
	numConsumers(0)
{
}

void DysonSphereParser::PowerNetworkStructures_Node::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected PowerNetworkStructures_Node version");
	}
	read(strm, id);
	read(strm, x);
	read(strm, y);
	read(strm, z);
	read(strm, connDistance2);
	read(strm, coverRadius2);
	read(strm, genId);
	read(strm, accId);
	read(strm, excId);
	read(strm, numConnIdsForLoad);
	read(strm, numLineIdsForLoad);
	read(strm, numConsumers);
	read(strm, connIdsForLoad, numConnIdsForLoad);
	read(strm, lineIdsForLoad, numLineIdsForLoad);
	read(strm, consumers, numConsumers);
}

DysonSphereParser::PowerNetwork::PowerNetwork() :
	version(0),
	id(0),
	numNodes(0),
	numConsumers(0),
	numGenerators(0),
	numAccumulators(0),
	numExchangers(0)
{
}

void DysonSphereParser::PowerNetwork::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected PowerNetwork version");
	}
	read(strm, id);
	read(strm, numNodes);
	read(strm, numConsumers);
	read(strm, numGenerators);
	read(strm, numAccumulators);
	read(strm, numExchangers);
	readv(strm, nodes, numNodes);
	read(strm, consumers, numConsumers);
	read(strm, generators, numGenerators);
	read(strm, accumulators, numAccumulators);
	read(strm, exchangers, numExchangers);
}

DysonSphereParser::PowerSystem::PowerSystem() :
	version(0),
	generatorCapacity(0),
	genCursor(0),
	genRecycleCursor(0),
	nodeCapacity(0),
	nodeCursor(0),
	nodeRecycleCursor(0),
	consumerCapacity(0),
	consumerCursor(0),
	consumerRecycleCursor(0),
	accumulatorCapacity(0),
	accCursor(0),
	accRecycleCursor(0),
	accRecycle(0),
	exchangerCapacity(0),
	excCursor(0),
	excRecycleCursor(0),
	networkCapacity(0),
	netCursor(0),
	netRecycleCursor(0)
{
}

void DysonSphereParser::PowerSystem::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected PowerSystem version");
	}
	read(strm, generatorCapacity);
	read(strm, genCursor);
	read(strm, genRecycleCursor);
	readv(strm, genPool, genCursor - 1);
	read(strm, genRecycle, genRecycleCursor);
	read(strm, nodeCapacity);
	read(strm, nodeCursor);
	read(strm, nodeRecycleCursor);
	readv(strm, nodePool, nodeCursor - 1);
	read(strm, nodeRecycle, nodeRecycleCursor);
	read(strm, consumerCapacity);
	read(strm, consumerCursor);
	read(strm, consumerRecycleCursor);
	readv(strm, consumerPool, consumerCursor - 1);
	read(strm, consumerRecycle, consumerRecycleCursor);
	read(strm, accumulatorCapacity);
	read(strm, accCursor);
	read(strm, accRecycleCursor);
	readv(strm, accPool, accCursor - 1);
	read(strm, accRecycle, accRecycleCursor);
	read(strm, exchangerCapacity);
	read(strm, excCursor);
	read(strm, excRecycleCursor);
	readv(strm, excPool, excCursor - 1);
	read(strm, excRecycle, excRecycleCursor);
	read(strm, networkCapacity);
	read(strm, netCursor);
	read(strm, netRecycleCursor);
	powerNetworkIncludedFlag.resize(netCursor);
	for (auto it = powerNetworkIncludedFlag.begin(); it != powerNetworkIncludedFlag.end(); ++it)
	{
		read(strm, *it);
		if (*it)
		{
			netPool.push_back(PowerNetwork());
			netPool.rbegin()->parse(strm);
		}
	}
	read(strm, netRecycle, netRecycleCursor);
}

DysonSphereParser::MinerComponent::MinerComponent() :
	version(0),
	id(0),
	entityId(0),
	pcId(0),
	type(DysonSphereParser::MinerComponent::EMinerType::None),
	speed(0),
	time(0),
	period(0),
	insertTarget(0),
	workstate(DysonSphereParser::MinerComponent::EWorkState::Idle),
	veinCount(0),
	currentVeinIndex(0),
	minimumVeinAmount(0),
	productId(0),
	productCount(0),
	seed(0)
{
}

void DysonSphereParser::MinerComponent::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected MinerComponent version");
	}
	read(strm, id);
	read(strm, entityId);
	read(strm, pcId);
	read<DysonSphereParser::MinerComponent::EMinerType, int32_t>(strm, type);
	read(strm, speed);
	read(strm, time);
	read(strm, period);
	read(strm, insertTarget);
	read<DysonSphereParser::MinerComponent::EWorkState, int32_t>(strm, workstate);
	read(strm, veinCount);
	read(strm, veins, veinCount);
	read(strm, currentVeinIndex);
	read(strm, minimumVeinAmount);
	read(strm, productId);
	read(strm, productCount);
	read(strm, seed);
}

DysonSphereParser::InserterComponent::InserterComponent() :
	version(0),
	id(0),
	entityId(0),
	pcId(0),
	stage(DysonSphereParser::InserterComponent::EInserterStage::Picking),
	speed(0),
	time(0),
	stt(0),
	delay(0),
	pickTarget(0),
	insertTarget(0),
	careNeeds(false),
	canStack(false),
	pickOffset(0),
	insertOffset(0),
	filter(0),
	itemId(0),
	stackCount(0),
	stackSize(0),
	t1(0),
	t2(0)
{
}

void DysonSphereParser::InserterComponent::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected InserterComponent version");
	}
	read(strm, id);
	read(strm, entityId);
	read(strm, pcId);
	read<DysonSphereParser::InserterComponent::EInserterStage, int32_t>(strm, stage);
	read(strm, speed);
	read(strm, time);
	read(strm, stt);
	read(strm, delay);
	read(strm, pickTarget);
	read(strm, insertTarget);
	read(strm, careNeeds);
	read(strm, canStack);
	read(strm, pickOffset);
	read(strm, insertOffset);
	read(strm, filter);
	read(strm, itemId);
	read(strm, stackCount);
	read(strm, stackSize);
	pos2.parse(strm);
	rot2.parse(strm);
	read(strm, t1);
	read(strm, t2);
}

DysonSphereParser::AssemblerComponent::AssemblerComponent() :
	version(0),
	id(0),
	entityId(0),
	pcId(0),
	replicating(false),
	outputing(false),
	speed(0),
	time(0),
	recipeId(0),
	recipeType(DysonSphereParser::AssemblerComponent::ERecipeType::None),
	timeSpend(0),
	numRequires(0),
	numRequireCounts(0),
	numServed(0),
	numNeeds(0),
	numProducts(0),
	numProductCounts(0),
	numProduced(0)
{
}

void DysonSphereParser::AssemblerComponent::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected AssemblerComponent version");
	}
	read(strm, id);
	read(strm, entityId);
	read(strm, pcId);
	read(strm, replicating);
	read(strm, outputing);
	read(strm, speed);
	read(strm, time);
	read(strm, recipeId);
	if (recipeId > 0)
	{
		read<DysonSphereParser::AssemblerComponent::ERecipeType, int32_t>(strm, recipeType);
		read(strm, timeSpend);
		read(strm, numRequires);
		read(strm, requires, numRequires);
		read(strm, numRequireCounts);
		read(strm, requireCounts, numRequireCounts);
		read(strm, numServed);
		read(strm, served, numServed);
		read(strm, numNeeds);
		read(strm, needs, numNeeds);
		read(strm, numProducts);
		read(strm, products, numProducts);
		read(strm, numProductCounts);
		read(strm, productCounts, numProductCounts);
		read(strm, numProduced);
		read(strm, produced, numProduced);
	}
}

DysonSphereParser::FractionateComponent::FractionateComponent() :
	version(0),
	id(0),
	entityId(0),
	pcId(0),
	belt0(0),
	belt1(0),
	belt2(0),
	isOutput0(false),
	isOutput1(false),
	isOutput2(false),
	isWorking(false),
	produceProb(0.0),
	need(0),
	product(0),
	needCurrCount(0),
	productCurrCount(0),
	oriProductCurrCount(0),
	progress(0),
	isRand(false),
	fractionateSuccess(false),
	needMaxCount(0),
	productMaxCount(0),
	oriProductMaxCount(0),
	seed(0)
{
}

void DysonSphereParser::FractionateComponent::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected FractionateComponent version");
	}
	read(strm, id);
	read(strm, entityId);
	read(strm, pcId);
	read(strm, belt0);
	read(strm, belt1);
	read(strm, belt2);
	read(strm, isOutput0);
	read(strm, isOutput1);
	read(strm, isOutput2);
	read(strm, isWorking);
	read(strm, produceProb);
	read(strm, need);
	read(strm, product);
	read(strm, needCurrCount);
	read(strm, productCurrCount);
	read(strm, oriProductCurrCount);
	read(strm, progress);
	read(strm, isRand);
	read(strm, fractionateSuccess);
	read(strm, needMaxCount);
	read(strm, productMaxCount);
	read(strm, oriProductMaxCount);
	read(strm, seed);
}

DysonSphereParser::EjectorComponent::EjectorComponent() :
	version(0),
	id(0),
	entityId(0),
	planetId(0),
	pcId(0),
	direction(0),
	time(0),
	fired(false),
	chargeSpend(0),
	coldSpend(0),
	bulletId(0),
	bulletCount(0),
	orbitId(0),
	pivotY(0.0),
	muzzleY(0.0),
	localAlt(0.0)
{
}

void DysonSphereParser::EjectorComponent::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected EjectorComponent version");
	}
	read(strm, id);
	read(strm, entityId);
	read(strm, planetId);
	read(strm, pcId);
	read(strm, direction);
	read(strm, time);
	read(strm, fired);
	read(strm, chargeSpend);
	read(strm, coldSpend);
	read(strm, bulletId);
	read(strm, bulletCount);
	read(strm, orbitId);
	read(strm, pivotY);
	read(strm, muzzleY);
	localPosN.parse(strm);
	read(strm, localAlt);
	localRot.parse(strm);
	localDir.parse(strm);
}

DysonSphereParser::SiloComponent::SiloComponent() :
	version(0),
	id(0),
	entityId(0),
	planetId(0),
	pcId(0),
	direction(0),
	time(0),
	fired(false),
	chargeSpend(0),
	coldSpend(0),
	bulletId(0),
	bulletCount(0),
	autoIndex(0),
	hasNode(false)
{
}

void DysonSphereParser::SiloComponent::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected SiloComponent version");
	}
	read(strm, id);
	read(strm, entityId);
	read(strm, planetId);
	read(strm, pcId);
	read(strm, direction);
	read(strm, time);
	read(strm, fired);
	read(strm, chargeSpend);
	read(strm, coldSpend);
	read(strm, bulletId);
	read(strm, bulletCount);
	read(strm, autoIndex);
	read(strm, hasNode);
	localPos.parse(strm);
	localRot.parse(strm);
}

DysonSphereParser::LabComponent::LabComponent() :
	version(0),
	id(0),
	entityId(0),
	pcId(0),
	nextLabId(0),
	replicating(false),
	outputing(false),
	time(0),
	hashBytes(0),
	researchMode(false),
	recipeId(0),
	techId(0),
	timeSpend(0),
	numRequires(0),
	numRequireCounts(0),
	numServed(0),
	numNeeds(0),
	numProducts(0),
	numProductCounts(0),
	numProduced(0),
	numMatrixPoints(0),
	numMatrixServed(0)
{
}

void DysonSphereParser::LabComponent::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected LabComponent version");
	}
	read(strm, id);
	read(strm, entityId);
	read(strm, pcId);
	read(strm, nextLabId);
	read(strm, replicating);
	read(strm, outputing);
	read(strm, time);
	read(strm, hashBytes);
	read(strm, researchMode);
	read(strm, recipeId);
	read(strm, techId);
	if (researchMode)
	{
		read(strm, numMatrixPoints);
		read(strm, matrixPoints, numMatrixPoints);
		read(strm, numMatrixServed);
		read(strm, matrixServed, numMatrixServed);
		read(strm, numNeeds);
		read(strm, needs, numNeeds);
	}
	else if (recipeId > 0)
	{
		read(strm, timeSpend);
		read(strm, numRequires);
		read(strm, requires, numRequires);
		read(strm, numRequireCounts);
		read(strm, requireCounts, numRequireCounts);
		read(strm, numServed);
		read(strm, served, numServed);
		read(strm, numNeeds);
		read(strm, needs, numNeeds);
		read(strm, numProducts);
		read(strm, products, numProducts);
		read(strm, numProductCounts);
		read(strm, productCounts, numProductCounts);
		read(strm, numProduced);
		read(strm, produced, numProduced);
	}
}

DysonSphereParser::FactorySystem::FactorySystem() :
	version(0),
	minerCapacity(0),
	minerCursor(0),
	minerRecycleCursor(0),
	inserterCapacity(0),
	inserterCursor(0),
	inserterRecycleCursor(0),
	assemblerCapacity(0),
	assemblerCursor(0),
	assemblerRecycleCursor(0),
	fractionateCapacity(0),
	fractionateCursor(0),
	fractionateRecycleCursor(0),
	ejectorCapacity(0),
	ejectorCursor(0),
	ejectorRecycleCursor(0),
	siloCapacity(0),
	siloCursor(0),
	siloRecycleCursor(0),
	labCapacity(0),
	labCursor(0),
	labRecycleCursor(0)
{
}

void DysonSphereParser::FactorySystem::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected FactorySystem version");
	}
	read(strm, minerCapacity);
	read(strm, minerCursor);
	read(strm, minerRecycleCursor);
	readv(strm, minerPool, minerCursor - 1);
	read(strm, minerRecycle, minerRecycleCursor);
	read(strm, inserterCapacity);
	read(strm, inserterCursor);
	read(strm, inserterRecycleCursor);
	readv(strm, inserterPool, inserterCursor - 1);
	read(strm, inserterRecycle, inserterRecycleCursor);
	read(strm, assemblerCapacity);
	read(strm, assemblerCursor);
	read(strm, assemblerRecycleCursor);
	readv(strm, assemblerPool, assemblerCursor - 1);
	read(strm, assemblerRecycle, assemblerRecycleCursor);
	read(strm, fractionateCapacity);
	read(strm, fractionateCursor);
	read(strm, fractionateRecycleCursor);
	readv(strm, fractionatePool, fractionateCursor - 1);
	read(strm, fractionateRecycle, fractionateRecycleCursor);
	read(strm, ejectorCapacity);
	read(strm, ejectorCursor);
	read(strm, ejectorRecycleCursor);
	readv(strm, ejectorPool, ejectorCursor - 1);
	read(strm, ejectorRecycle, ejectorRecycleCursor);
	read(strm, siloCapacity);
	read(strm, siloCursor);
	read(strm, siloRecycleCursor);
	readv(strm, siloPool, siloCursor - 1);
	read(strm, siloRecycle, siloRecycleCursor);
	read(strm, labCapacity);
	read(strm, labCursor);
	read(strm, labRecycleCursor);
	readv(strm, labPool, labCursor - 1);
	read(strm, labRecycle, labRecycleCursor);
}

DysonSphereParser::DroneData::DroneData() :
	version(0),
	endId(0),
	direction(0.0),
	maxt(0.0),
	t(0.0),
	itemId(0),
	itemCount(0),
	gene(0)
{
}

void DysonSphereParser::DroneData::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected DroneData version");
	}
	begin.parse(strm);
	end.parse(strm);
	read(strm, endId);
	read(strm, direction);
	read(strm, maxt);
	read(strm, t);
	read(strm, itemId);
	read(strm, itemCount);
	read(strm, gene);
}

DysonSphereParser::LocalLogisticOrder::LocalLogisticOrder() :
	version(0),
	otherStationId(0),
	thisIndex(0),
	otherIndex(0),
	itemId(0),
	thisOrdered(0),
	otherOrdered(0)
{
}

void DysonSphereParser::LocalLogisticOrder::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected LocalLogisticOrder version");
	}
	read(strm, otherStationId);
	read(strm, thisIndex);
	read(strm, otherIndex);
	read(strm, itemId);
	read(strm, thisOrdered);
	read(strm, otherOrdered);
}

DysonSphereParser::ShipData::ShipData() :
	version(0),
	stage(0),
	planetA(0),
	planetB(0),
	uSpeed(0.0),
	warpState(0.0),
	uAngularSpeed(0.0),
	otherGId(0),
	direction(0),
	t(0.0),
	itemId(0),
	itemCount(0),
	gene(0),
	shipIndex(0),
	warperCnt(0)
{
}

void DysonSphereParser::ShipData::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected ShipData version");
	}
	read(strm, stage);
	read(strm, planetA);
	read(strm, planetB);
	uPos.parse(strm);
	uVel.parse(strm);
	read(strm, uSpeed);
	read(strm, warpState);
	uRot.parse(strm);
	uAngularVel.parse(strm);
	read(strm, uAngularSpeed);
	pPosTemp.parse(strm);
	pRotTemp.parse(strm);
	read(strm, otherGId);
	read(strm, direction);
	read(strm, t);
	read(strm, itemId);
	read(strm, itemCount);
	read(strm, gene);
	read(strm, shipIndex);
	read(strm, warperCnt);
}

DysonSphereParser::RemoteLogisticOrder::RemoteLogisticOrder() :
	version(0),
	otherStationGId(0),
	thisIndex(0),
	otherIndex(0),
	itemId(0),
	thisOrdered(0),
	otherOrdered(0)
{
}

void DysonSphereParser::RemoteLogisticOrder::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected RemoteLogisticOrder version");
	}
	read(strm, otherStationGId);
	read(strm, thisIndex);
	read(strm, otherIndex);
	read(strm, itemId);
	read(strm, thisOrdered);
	read(strm, otherOrdered);
}

DysonSphereParser::StationStore::StationStore() :
	version(0),
	itemId(0),
	count(0),
	localOrder(0),
	remoteOrder(0),
	max(0),
	localLogic(DysonSphereParser::StationStore::ELogisticStorage::None),
	remoteLogic(DysonSphereParser::StationStore::ELogisticStorage::None)
{
}

void DysonSphereParser::StationStore::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected StationStore version");
	}
	read(strm, itemId);
	read(strm, count);
	read(strm, localOrder);
	read(strm, remoteOrder);
	read(strm, max);
	read<DysonSphereParser::StationStore::ELogisticStorage, int32_t>(strm, localLogic);
	read<DysonSphereParser::StationStore::ELogisticStorage, int32_t>(strm, remoteLogic);
}

DysonSphereParser::SlotData::SlotData() :
	dir(0),
	beltId(0),
	storageIdx(0),
	counter(0)
{
}

void DysonSphereParser::SlotData::parse(std::ifstream& strm)
{
	read(strm, dir);
	read(strm, beltId);
	read(strm, storageIdx);
	read(strm, counter);
}

DysonSphereParser::StationComponent::StationComponent() :
	version(0),
	id(0),
	gid(0),
	entityId(0),
	planetId(0),
	pcId(0),
	gene(0),
	isStellar(false),
	nameIsIncludedFlag(false),
	energy(0),
	energyPerTick(0),
	energyMax(0),
	warperCount(0),
	warperMaxCount(0),
	idleDroneCount(0),
	workDroneCount(0),
	workDroneArraySize(0),
	idleShipCount(0),
	workShipCount(0),
	idleShipIndices(0),
	workShipIndices(0),
	arraySize(0),
	numStorage(0),
	numSlots(0),
	localPairProcess(0),
	remotePairProcess(0),
	nextShipIndex(0),
	isCollector(false),
	numCollectionIds(0),
	numCollectionPerTick(0),
	numCurrentCollections(0),
	collectSpeed(0),
	tripRangeDrones(0.0),
	tripRangeShips(0.0),
	includeOrbitCollector(false),
	warpEnableDist(0.0),
	warperNecessary(false),
	deliveryDrones(0),
	deliveryShips(0)
{
}

void DysonSphereParser::StationComponent::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 2)
	{
		assert(false);
		throw std::exception("Unexpected StationComponent version");
	}
	read(strm, id);
	read(strm, gid);
	read(strm, entityId);
	read(strm, planetId);
	read(strm, pcId);
	read(strm, gene);
	droneDock.parse(strm);
	shipDockPos.parse(strm);
	shipDockRot.parse(strm);
	read(strm, isStellar);
	read(strm, nameIsIncludedFlag);
	int64_t pos = strm.tellg();
	if (nameIsIncludedFlag > 0)
	{
		read(strm, name);
	}
	read(strm, energy);
	read(strm, energyPerTick);
	read(strm, energyMax);
	read(strm, warperCount);
	read(strm, warperMaxCount);
	read(strm, idleDroneCount);
	read(strm, workDroneCount);
	read(strm, workDroneArraySize);
	readv(strm, workDroneDatas, workDroneCount);
	readv(strm, workDroneOrders, workDroneCount);
	read(strm, idleShipCount);
	read(strm, workShipCount);
	read(strm, idleShipIndices);
	read(strm, workShipIndices);
	read(strm, arraySize);
	readv(strm, workShipDatas, workShipCount);
	readv(strm, workShipOrders, workShipCount);
	read(strm, numStorage);
	readv(strm, storage, numStorage);
	read(strm, numSlots);
	readv(strm, slots, numSlots);
	read(strm, localPairProcess);
	read(strm, remotePairProcess);
	read(strm, nextShipIndex);
	read(strm, isCollector);
	read(strm, numCollectionIds);
	read(strm, collectionIds, numCollectionIds);
	read(strm, numCollectionPerTick);
	read(strm, collectionPerTick, numCollectionPerTick);
	read(strm, numCurrentCollections);
	read(strm, currentCollections, numCurrentCollections);
	read(strm, collectSpeed);
	read(strm, tripRangeDrones);
	read(strm, tripRangeShips);
	read(strm, includeOrbitCollector);
	read(strm, warpEnableDist);
	read(strm, warperNecessary);
	read(strm, deliveryDrones);
	read(strm, deliveryShips);
}

DysonSphereParser::PlanetTransport::PlanetTransport() :
	version(0),
	stationCursor(0),
	stationCapacity(0),
	stationRecycleCursor(0)
{
}

void DysonSphereParser::PlanetTransport::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected PlanetTransport version");
	}
	read(strm, stationCursor);
	read(strm, stationCapacity);
	read(strm, stationRecycleCursor);
	readi(strm, stationIndex, stationPool, stationCursor - 1);
	read(strm, stationRecycle, stationRecycleCursor);
}

DysonSphereParser::MonsterComponent::MonsterComponent() :
	version(0),
	id(0),
	entityId(0),
	walkSpeed(0.0),
	direction(0),
	stopTime(0.0),
	t(0.0),
	stopCurrentTime(0.0),
	monsterState(DysonSphereParser::MonsterComponent::EMonsterState::Null),
	stepDistance(0.0)
{
}

void DysonSphereParser::MonsterComponent::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected MonsterComponent version");
	}
	read(strm, id);
	read(strm, entityId);
	read(strm, walkSpeed);
	point0.parse(strm);
	point1.parse(strm);
	point2.parse(strm);
	read(strm, direction);
	read(strm, stopTime);
	read(strm, t);
	read(strm, stopCurrentTime);
	read<DysonSphereParser::MonsterComponent::EMonsterState, int32_t>(strm, monsterState);
	read(strm, stepDistance);
}

DysonSphereParser::MonsterSystem::MonsterSystem() :
	version(0),
	monsterCapacity(0),
	monsterCursor(0),
	monsterRecycleCursor(0)
{
}

void DysonSphereParser::MonsterSystem::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected MonsterSystem version");
	}
	read(strm, monsterCapacity);
	read(strm, monsterCursor);
	read(strm, monsterRecycleCursor);
	readv(strm, monsterPool, monsterCursor - 1);
	read(strm, monsterRecycle, monsterRecycleCursor);
}

DysonSphereParser::PlatformSystem::PlatformSystem() :
	version(0),
	reformDataByteCount(0),
	reformOffsetsByteCount(0)
{
}

void DysonSphereParser::PlatformSystem::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected PlatformSystem version");
	}
	read(strm, reformDataByteCount);
	read(strm, reformData, reformDataByteCount);
	read(strm, reformOffsetsByteCount);
	read(strm, reformOffsets, reformOffsetsByteCount);
}

DysonSphereParser::PlanetFactory::PlanetFactory() :
	version(0),
	planetId(0),
	entityCapacity(0),
	entityCursor(0),
	entityRecycleCursor(0),
	prebuildCapacity(0),
	prebuildCursor(0),
	prebuildRecycleCursor(0),
	vegeCapacity(0),
	vegeCursor(0),
	vegeRecycleCursor(0),
	veinCapacity(0),
	veinCursor(0),
	veinRecycleCursor(0)
{
}

void DysonSphereParser::PlanetFactory::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 1)
	{
		assert(false);
		throw std::exception("Unexpected PlanetFactory version");
	}
	read(strm, planetId);
	planet.parse(strm);
	read(strm, entityCapacity);
	read(strm, entityCursor);
	read(strm, entityRecycleCursor);
	readv(strm, entityPool, entityCursor - 1);
	readv(strm, entityAnimPool, entityCursor - 1);
	readv(strm, entitySignPool, entityCursor - 1);
	read(strm, entityConnPool, entityCursor * 16 - 16);
	read(strm, entityRecycle, entityRecycleCursor);
	read(strm, prebuildCapacity);
	read(strm, prebuildCursor);
	read(strm, prebuildRecycleCursor);
	readv(strm, prebuildPool, prebuildCursor - 1);
	read(strm, prebuildConnPool, prebuildCursor * 16 - 16);
	read(strm, prebuildRecycle, prebuildRecycleCursor);
	read(strm, vegeCapacity);
	read(strm, vegeCursor);
	read(strm, vegeRecycleCursor);
	readv(strm, vegePool, vegeCursor - 1);
	read(strm, vegeRecycle, vegeRecycleCursor);
	read(strm, veinCapacity);
	read(strm, veinCursor);
	read(strm, veinRecycleCursor);
	readv(strm, veinPool, veinCursor - 1);
	read(strm, veinRecycle, veinRecycleCursor);
	readv(strm, veinAnimPool, veinCursor - 1);
	cargoContainer.parse(strm);
	cargoTraffic.parse(strm);
	factoryStorage.parse(strm);
	powerSystem.parse(strm);
	factorySystem.parse(strm);
	transport.parse(strm);
	monsterSystem.parse(strm);
	platformSystem.parse(strm);
}

DysonSphereParser::DysonSail::DysonSail() :
	st(0.0),
	gs(0.0)
{
}

void DysonSphereParser::DysonSail::parse(std::ifstream& strm)
{
	read(strm, st);
	p.parse(strm);
	v.parse(strm);
	read(strm, gs);
}

DysonSphereParser::DysonSailInfo::DysonSailInfo() :
	orbit(0),
	node(0),
	kill(0)
{
}

void DysonSphereParser::DysonSailInfo::parse(std::ifstream& strm)
{
	read(strm, orbit);
	read(strm, node);
	read(strm, kill);
	posr.parse(strm);
}

DysonSphereParser::SailOrbit::SailOrbit() :
	version(0),
	id(0),
	radius(0.0),
	count(0),
	enabled(false)
{
}

void DysonSphereParser::SailOrbit::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected SailOrbit version");
	}
	read(strm, id);
	read(strm, radius);
	rotation.parse(strm);
	up.parse(strm);
	read(strm, count);
	read(strm, enabled);
}

DysonSphereParser::ExpiryOrder::ExpiryOrder() :
	time(0),
	index(0)
{
}

void DysonSphereParser::ExpiryOrder::parse(std::ifstream& strm)
{
	read(strm, time);
	read(strm, index);
}

DysonSphereParser::AbsorbOrder::AbsorbOrder() :
	time(0),
	index(0),
	layer(0),
	node(0)
{
}

void DysonSphereParser::AbsorbOrder::parse(std::ifstream& strm)
{
	read(strm, time);
	read(strm, index);
	read(strm, layer);
	read(strm, node);
}

DysonSphereParser::SailBullet::SailBullet() :
	version(0),
	id(0),
	t(0.0),
	maxt(0.0),
	state(0)
{
}

void DysonSphereParser::SailBullet::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected SailBullet version");
	}
	read(strm, id);
	read(strm, t);
	read(strm, maxt);
	read(strm, state);
	rBegin.parse(strm);
	rEnd.parse(strm);
	lBegin.parse(strm);
	uEndVel.parse(strm);
	uBegin.parse(strm);
	uEnd.parse(strm);
}

DysonSphereParser::DysonSwarm::DysonSwarm() :
	version(0),
	randSeed(0),
	sailCapacity(0),
	sailCursor(0),
	sailRecycleCursor(0),
	orbitCapacity(0),
	orbitCursor(0),
	numExpiryOrder(0),
	expiryCursor(0),
	expiryEnding(0),
	numAbsorbOrder(0),
	absorbCursor(0),
	absorbEnding(0),
	bulletCapacity(0),
	bulletCursor(0),
	bulletRecycleCursor(0)
{
}

void DysonSphereParser::DysonSwarm::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 4)
	{
		assert(false);
		throw std::exception("Unexpected DysonSwarm version");
	}
	read(strm, randSeed);
	read(strm, sailCapacity);
	read(strm, sailCursor);
	read(strm, sailRecycleCursor);
	readv(strm, sailPoolForSave, sailCursor);
	readv(strm, sailInfos, sailCursor);
	read(strm, sailRecycle, sailRecycleCursor);
	read(strm, orbitCapacity);
	read(strm, orbitCursor);
	readv(strm, orbits, orbitCursor - 1);
	read(strm, numExpiryOrder);
	read(strm, expiryCursor);
	read(strm, expiryEnding);
	readv(strm, expiryOrder, numExpiryOrder);
	read(strm, numAbsorbOrder);
	read(strm, absorbCursor);
	read(strm, absorbEnding);
	readv(strm, absorbOrder, numAbsorbOrder);
	read(strm, bulletCapacity);
	read(strm, bulletCursor);
	read(strm, bulletRecycleCursor);
	readv(strm, bulletPool, bulletCursor - 1);
	read(strm, bulletRecycle, bulletRecycleCursor);
}

DysonSphereParser::DysonNode::DysonNode() :
	version(0),
	id(0),
	protoId(0),
	layerId(0),
	use(false),
	reserved(false),
	sp(0),
	spMax(0),
	spOrdered(0),
	cpOrdered(0),
	rid(0),
	frameTurn(0),
	shellTurn(0),
	_spReq(0),
	_cpReq(0)
{
}

void DysonSphereParser::DysonNode::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 4)
	{
		assert(false);
		throw std::exception("Unexpected DysonNode version");
	}
	read(strm, id);
	read(strm, protoId);
	read(strm, layerId);
	read(strm, use);
	read(strm, reserved);
	pos.parse(strm);
	read(strm, sp);
	read(strm, spMax);
	read(strm, spOrdered);
	read(strm, cpOrdered);
	read(strm, rid);
	read(strm, frameTurn);
	read(strm, shellTurn);
	read(strm, _spReq);
	read(strm, _cpReq);
}

DysonSphereParser::DysonFrame::DysonFrame() :
	version(0),
	id(0),
	protoId(0),
	layerId(0),
	reserved(false),
	nodeId(0),
	nodeId2(0),
	euler(false),
	spA(0),
	spB(0),
	spMax(0)
{
}

void DysonSphereParser::DysonFrame::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected DysonFrame version");
	}
	read(strm, id);
	read(strm, protoId);
	read(strm, layerId);
	read(strm, reserved);
	read(strm, nodeId);
	read(strm, nodeId2);
	read(strm, euler);
	read(strm, spA);
	read(strm, spB);
	read(strm, spMax);
}

DysonSphereParser::DysonShell::DysonShell() :
	version(0),
	id(0),
	protoId(0),
	layerId(0),
	randSeed(0),
	numPolygon(0),
	numDysonNode(0),
	vertexCount(0),
	triangleCount(0),
	numVerts(0),
	numPqArr(0),
	numTris(0),
	numVAdjs(0),
	numVertAttr(0),
	numVertsq(0),
	numVertsqOffset(0),
	numNodecps(0),
	numVertcps(0),
	vertRecycleArraySize(0),
	vertRecycleCursor(0)
{
}

void DysonSphereParser::DysonShell::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected DysonShell version");
	}
	read(strm, id);
	read(strm, protoId);
	read(strm, layerId);
	read(strm, randSeed);
	read(strm, numPolygon);
	readv(strm, polygon, numPolygon);
	read(strm, numDysonNode);
	read(strm, nodeId, numDysonNode);
	read(strm, vertexCount);
	read(strm, triangleCount);
	read(strm, numVerts);
	readv(strm, verts, numVerts);
	read(strm, numPqArr);
	readv(strm, pqArr, numPqArr);
	read(strm, numTris);
	read(strm, tris, numTris);
	read(strm, numVAdjs);
	read(strm, vAdjs, numVAdjs);
	read(strm, numVertAttr);
	read(strm, vertAttr, numVertAttr);
	read(strm, numVertsq);
	read(strm, vertsq, numVertsq);
	read(strm, numVertsqOffset);
	read(strm, vertsqOffset, numVertsqOffset);
	read(strm, numNodecps);
	read(strm, nodecps, numNodecps);
	read(strm, numVertcps);
	read(strm, vertcps, numVertcps);
	read(strm, vertRecycleArraySize);
	read(strm, vertRecycleCursor);
	read(strm, vertRecycle, vertRecycleCursor);
}

DysonSphereParser::DysonSphereLayer::DysonSphereLayer() :
	version(0),
	id(0),
	orbitRadius(0.0),
	orbitAngularSpeed(0.0),
	currentAngle(0.0),
	gridMode(0),
	nodeCapacity(0),
	nodeCursor(0),
	nodeRecycleCursor(0),
	frameCapacity(0),
	frameCursor(0),
	frameRecycleCursor(0),
	shellCapacity(0),
	shellCursor(0),
	shellRecycleCursor(0)
{
}

void DysonSphereParser::DysonSphereLayer::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected DysonSphereLayer version");
	}
	read(strm, id);
	read(strm, orbitRadius);
	orbitRotation.parse(strm);
	read(strm, orbitAngularSpeed);
	read(strm, currentAngle);
	currentRotation.parse(strm);
	nextRotation.parse(strm);
	read(strm, gridMode);
	read(strm, nodeCapacity);
	read(strm, nodeCursor);
	read(strm, nodeRecycleCursor);
	readi(strm, dysonNodeIndex, nodePool, nodeCursor - 1);
	read(strm, nodeRecycle, nodeRecycleCursor);
	read(strm, frameCapacity);
	read(strm, frameCursor);
	read(strm, frameRecycleCursor);
	readi(strm, dysonFrameIndex, framePool, frameCursor - 1);
	read(strm, frameRecycle, frameRecycleCursor);
	read(strm, shellCapacity);
	read(strm, shellCursor);
	read(strm, shellRecycleCursor);
	readi(strm, dysonShellIndex, shellPool, shellCursor - 1);
	read(strm, shellRecycle, shellRecycleCursor);
}

DysonSphereParser::DysonRocket::DysonRocket() :
	version(0),
	id(0),
	nodeLayerId(0),
	nodeId(0),
	planetId(0),
	t(0.0),
	uSpeed(0.0)
{
}

void DysonSphereParser::DysonRocket::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected DysonRocket version");
	}
	read(strm, id);
	read(strm, nodeLayerId);
	read(strm, nodeId);
	read(strm, planetId);
	read(strm, t);
	read(strm, uSpeed);
	uPos.parse(strm);
	uRot.parse(strm);
	uVel.parse(strm);
	launch.parse(strm);
}

DysonSphereParser::DysonNodeRData::DysonNodeRData() :
	version(0),
	id(0),
	layerId(0),
	angularVel(0.0)
{
}

void DysonSphereParser::DysonNodeRData::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 0)
	{
		assert(false);
		throw std::exception("Unexpected DysonNodeRData version");
	}
	read(strm, id);
	read(strm, layerId);
	pos.parse(strm);
	read(strm, angularVel);
	layerRot.parse(strm);
}

DysonSphereParser::DysonSphere::DysonSphere() :
	version(0),
	randSeed(0),
	twelveTwelve(0),
	layerCount(0),
	numDysonSphereLayer(0),
	rocketCapacity(0),
	rocketCursor(0),
	rocketRecycleCursor(0),
	autoNodeCount(0),
	numAutoNodes(0),
	nrdCapacity(0),
	nrdCursor(0),
	nrdRecycleCursor(0)
{
}

void DysonSphereParser::DysonSphere::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 2)
	{
		assert(false);
		throw std::exception("Unexpected DysonSphere version");
	}
	read(strm, randSeed);
	swarm.parse(strm);
	read(strm, twelveTwelve);
	if (twelveTwelve != 1212)
	{
		assert(false);
		throw std::exception("Unexpected DysonSphere twelveTwelve");
	}
	read(strm, layerCount);
	read(strm, numDysonSphereLayer);
	readi(strm, dysonSphereLayerIndex, dysonSphereLayer, numDysonSphereLayer - 1);
	read(strm, rocketCapacity);
	read(strm, rocketCursor);
	read(strm, rocketRecycleCursor);
	readv(strm, rocketPool, rocketCursor - 1);
	read(strm, rocketRecycle, rocketRecycleCursor);
	read(strm, autoNodeCount);
	read(strm, numAutoNodes);
	autoNodeIncludedFlag.resize(numAutoNodes);
	for (auto it = autoNodeIncludedFlag.begin(); it != autoNodeIncludedFlag.end(); ++it)
	{
		read(strm, *it);
		if (*it > 0)
		{
			layerId.push_back(0);
			read(strm, *layerId.rbegin());
			nodeId.push_back(0);
			read(strm, *nodeId.rbegin());
		}
	}
	read(strm, nrdCapacity);
	read(strm, nrdCursor);
	read(strm, nrdRecycleCursor);
	readv(strm, nrdPool, nrdCursor);
	read(strm, nrdRecycle, nrdRecycleCursor);
}

DysonSphereParser::GameData::GameData() :
	version(0),
	gameTick(0),
	hidePlayerModel(false),
	disableController(false),
	planetId(0),
	factoryCount(0),
	galaxyStarCount(0)
{
}

void DysonSphereParser::GameData::parse(std::ifstream& strm)
{
	read(strm, version);
	if (version != 2)
	{
		assert(false);
		throw std::exception("Unexpected GameData version");
	}
	read(strm, gameName);
	gameDesc.parse(strm);
	read(strm, gameTick);
	preferences.parse(strm);
	history.parse(strm);
	read(strm, hidePlayerModel);
	read(strm, disableController);
	statistics.parse(strm);
	read(strm, planetId);
	mainPlayer.parse(strm);
	read(strm, factoryCount);
	galacticTransport.parse(strm);
	readv(strm, factories, factoryCount);
	read(strm, galaxyStarCount);
	readi(strm, dysonSphereIndex, dysonSpheres, galaxyStarCount);
}

DysonSphereParser::GameSave::GameSave() :
	fileStreamLength(0),
	saveFileFormatNumber(0),
	majorGameVersion(0),
	minorGameVersion(0),
	releaseGameVersion(0),
	gameTick(0),
	nowTicks(0),
	sizeOfPngFile(0)
{
}

void DysonSphereParser::GameSave::parse(std::ifstream& strm)
{
	char vfsave[6] = { 0 };
	strm.read(vfsave, sizeof(vfsave));
	if (strncmp(vfsave, "VFSAVE", sizeof(vfsave)) != 0)
	{
		assert(false);
		throw std::exception("Unexpected vfsave");
	}

	read(strm, fileStreamLength);
	read(strm, saveFileFormatNumber);
	if (saveFileFormatNumber != 4)
	{
		assert(false);
		throw std::exception("Unexpected saveFileFormatNumber");
	}
	read(strm, majorGameVersion);
	read(strm, minorGameVersion);
	read(strm, releaseGameVersion);
	read(strm, gameTick);
	read(strm, nowTicks);
	read(strm, sizeOfPngFile);

	screenShotPngFile.resize(sizeOfPngFile);
	strm.read(reinterpret_cast<char*>(screenShotPngFile.data()), sizeOfPngFile);

	data.parse(strm);
}

template<typename CHAR>
DysonSphereParser::DysonSphereParser(const CHAR* const filename) :
	m_readSuccessFlag(false)
{
	std::ifstream strm(filename, std::ios_base::binary);
	if (!strm)
	{
		m_failureDescription = "Failed to open file";
		return;
	}

	try
	{
		gameSave.parse(strm);
	}
	catch (std::exception& e)
	{
		m_failureDescription = e.what();
		return;
	}

	m_readSuccessFlag = true;
}

int main(int argc, char* argv[])
{
	DysonSphereParser saveFile(L"specify path to .dsv here, char* or wchar_t*");

	if (!saveFile.m_readSuccessFlag)
	{
		std::cerr << "ERROR: Failed to parse save file: " << saveFile.m_failureDescription << std::endl;
		return 1;
	}

	std::cout << "Successfully parsed save file: " << saveFile.gameSave.data.gameName << std::endl;
	std::cout << std::endl;

	for (const auto& factory : saveFile.gameSave.data.factories)
	{
		std::cout << "Factory planet " << factory.planetId << std::endl;

#if 0
		std::cout << "  Vein pool:" << std::endl;
		for (const auto& vein : factory.veinPool)
		{
			if (vein.id != 0 || vein.amount != 0 || vein.type != DysonSphereParser::EVeinType::None)
			{
				std::cout << "    id=" << vein.id << ", amount=" << vein.amount << ", type=" << DysonSphereParser::toString(vein.type) << std::endl;
			}
		}

		std::cout << "  Vein amounts:" << std::endl;
#endif
		for (uint32_t type = 0; type < factory.planet.veinAmounts.size(); ++type)
		{
			const auto amount = factory.planet.veinAmounts[type];
			if (amount != 0)
			{
				if (type == static_cast<uint32_t>(DysonSphereParser::EVeinType::Oil))
				{
					std::cout << "    " << DysonSphereParser::toString(static_cast<DysonSphereParser::EVeinType>(type)) << ": " << ((double)amount * oilSpeedMultiplier) << std::endl;
				}
				else
				{
					std::cout << "    " << DysonSphereParser::toString(static_cast<DysonSphereParser::EVeinType>(type)) << ": " << amount << std::endl;
				}
			}
		}

#if 0
		std::cout << "  Vein groups:" << std::endl;
		for (const auto& vein : factory.planet.veinGroups)
		{
			std::cout << "    amount=" << vein.amount << ", count=" << vein.count << ", type=" << DysonSphereParser::toString(vein.type) << std::endl;
		}
#endif
	}

	return 0;
}
