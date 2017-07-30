// CorsaidCUEJNAWrapper.cpp : définit les fonctions exportées pour l'application DLL.
//

#include "stdafx.h"
#include "CorsairCUEJNAWrapper.h"
#include <malloc.h>

CORSAIRCUEJNAWRAPPER_API bool JNACorsairSetLedsColors(int size, CorsairLedColor* ledsColors) {
	return CorsairSetLedsColors(size, ledsColors);
}

CORSAIRCUEJNAWRAPPER_API bool JNACorsairSetLedsColorsAsync(int size, CorsairLedColor* ledsColors, void(*CallbackType)(void*, bool, CorsairError), void *context) {
	return CorsairSetLedsColorsAsync(size, ledsColors, CallbackType, context);
}

CORSAIRCUEJNAWRAPPER_API int JNACorsairGetDeviceCount() {
	return CorsairGetDeviceCount();
}

CORSAIRCUEJNAWRAPPER_API CorsairDeviceInfo *JNACorsairGetDeviceInfo(int deviceIndex) {
	return CorsairGetDeviceInfo(deviceIndex);
}

CORSAIRCUEJNAWRAPPER_API CorsairLedPositions *JNACorsairGetLedPositions() {
	return CorsairGetLedPositions();
}

CORSAIRCUEJNAWRAPPER_API CorsairLedPositions *JNACorsairGetLedPositionsByDeviceIndex(int deviceIndex) {
	return CorsairGetLedPositionsByDeviceIndex(deviceIndex);
}

CORSAIRCUEJNAWRAPPER_API CorsairLedId JNACorsairGetLedIdForKeyName(char keyName) {
	return CorsairGetLedIdForKeyName(keyName);
}

CORSAIRCUEJNAWRAPPER_API CorsairProtocolDetails* JNACorsairPerformProtocolHandshake() {
	CorsairProtocolDetails internalDetails = CorsairPerformProtocolHandshake();
	CorsairProtocolDetails* corsairPerformProtocolHandshakeResult = (CorsairProtocolDetails*)malloc(sizeof(CorsairDeviceInfo));
	corsairPerformProtocolHandshakeResult->breakingChanges = internalDetails.breakingChanges;
	corsairPerformProtocolHandshakeResult->sdkProtocolVersion = internalDetails.sdkProtocolVersion;
	corsairPerformProtocolHandshakeResult->sdkVersion = internalDetails.sdkVersion;
	corsairPerformProtocolHandshakeResult->serverProtocolVersion= internalDetails.serverProtocolVersion;
	corsairPerformProtocolHandshakeResult->serverVersion = internalDetails.serverVersion;
	return corsairPerformProtocolHandshakeResult;
}

CORSAIRCUEJNAWRAPPER_API CorsairError JNACorsairGetLastError() {
	return CorsairGetLastError();
}

CORSAIRCUEJNAWRAPPER_API bool JNACorsairReleaseControl(CorsairAccessMode accessMode) {
	return CorsairReleaseControl(accessMode);
}

CORSAIRCUEJNAWRAPPER_API bool JNACorsairRequestControl(CorsairAccessMode accessMode) {
	return CorsairRequestControl(accessMode);
}

