/**
 * @file Action.h
 * @brief contains the Action enum, see brief below.
 */

#ifndef KHUNSOLVER_INCLUDE_ACTION_H_
#define KHUNSOLVER_INCLUDE_ACTION_H_

/** 
 * @enum Action
 * @brief assign ints to actions for use in generating ActionNodes
 */
enum Action
{
  PREFLOP,
  FLOP,
  TURN,
  RIVER
};

#endif //KHUNSOLVER_INCLUDE_ACTION_H_