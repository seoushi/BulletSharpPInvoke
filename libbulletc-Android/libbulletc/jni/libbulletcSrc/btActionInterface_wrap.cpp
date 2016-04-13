#include <BulletCollision/CollisionDispatch/btCollisionWorld.h>
#include <BulletDynamics/Dynamics/btActionInterface.h>
#include <LinearMath/btIDebugDraw.h>

#include "btActionInterface_wrap.h"

btActionInterfaceWrapper::btActionInterfaceWrapper(pIAction_DebugDraw debugDrawCallback, pIAction_UpdateAction updateActionCallback,void* managedActionInterfaceWrap)
{
	_debugDrawCallback = debugDrawCallback;
	_updateActionCallback = updateActionCallback;
    _managedActionInterfaceWrapper = managedActionInterfaceWrap;
}

void btActionInterfaceWrapper::debugDraw(btIDebugDraw* debugDrawer)
{
	_debugDrawCallback(_managedActionInterfaceWrapper, debugDrawer);
}

void btActionInterfaceWrapper::updateAction(btCollisionWorld* collisionWorld, btScalar deltaTimeStep)
{
	_updateActionCallback(_managedActionInterfaceWrapper ,collisionWorld, deltaTimeStep);
}


btActionInterfaceWrapper* btActionInterfaceWrapper_new(pIAction_DebugDraw debugDrawCallback, pIAction_UpdateAction updateActionCallback,void* managedActionInterfaceWrap)
{
	return new btActionInterfaceWrapper(debugDrawCallback, updateActionCallback,managedActionInterfaceWrap);
}

void* bgActionInterface_getManagedWrapperPntr(btActionInterfaceWrapper* obj){
    return obj->_managedActionInterfaceWrapper;
}

/*
void btActionInterface_debugDraw(btActionInterface* obj, btIDebugDraw* debugDrawer)
{
	obj->debugDraw(debugDrawer);
}

void btActionInterface_updateAction(btActionInterface* obj, btCollisionWorld* collisionWorld, btScalar deltaTimeStep)
{
	obj->updateAction(collisionWorld, deltaTimeStep);
}
 */

void btActionInterface_delete(btActionInterface* obj)
{
	delete obj;
}
