/**
  ******************************************************************************
  * File Name          : TouchGFXGeneratedHAL.cpp
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

#include <TouchGFXGeneratedHAL.hpp>
#include <touchgfx/hal/OSWrappers.hpp>
#include <gui/common/FrontendHeap.hpp>

#include "stm32h7xx.h"

using namespace touchgfx;

void TouchGFXGeneratedHAL::initialize()
{
    HAL::initialize();
    registerEventListener(*(Application::getInstance()));
    enableLCDControllerInterrupt();
    enableInterrupts();
    setFrameBufferStartAddresses((void*)0xD0000000, (void*)0, (void*)0);
    /*
     * Set whether the DMA transfers are locked to the TFT update cycle. If
     * locked, DMA transfer will not begin until the TFT controller has finished
     * updating the display. If not locked, DMA transfers will begin as soon as
     * possible. Default is true (DMA is locked with TFT).
     */
    lockDMAToFrontPorch(true);
}

void TouchGFXGeneratedHAL::configureInterrupts()
{
    NVIC_SetPriority(DMA2D_IRQn, 9);
}

void TouchGFXGeneratedHAL::enableInterrupts()
{
    NVIC_EnableIRQ(DMA2D_IRQn);
}

void TouchGFXGeneratedHAL::disableInterrupts()
{
    NVIC_DisableIRQ(DMA2D_IRQn);
}

void TouchGFXGeneratedHAL::enableLCDControllerInterrupt()
{
}

bool TouchGFXGeneratedHAL::beginFrame()
{
    return HAL::beginFrame();
}

void TouchGFXGeneratedHAL::endFrame()
{
    HAL::endFrame();
    touchgfx::OSWrappers::signalRenderingDone();
}

inline uint8_t* TouchGFXGeneratedHAL::advanceFrameBufferToRect(uint8_t* fbPtr, const touchgfx::Rect& rect) const
{
    //       Advance vertically                   Advance horizontally
    fbPtr += rect.y * lcd().framebufferStride() + rect.x * 3;
    return fbPtr;
}

uint16_t* TouchGFXGeneratedHAL::getTFTFrameBuffer() const
{
    //getTFTFrameBuffer() not used for selected Frame Buffer Strategy
    return 0;
}

void TouchGFXGeneratedHAL::setTFTFrameBuffer(uint16_t* adr)
{
    //setTFTFrameBuffer() not used for selected display interface
}

void TouchGFXGeneratedHAL::flushFrameBuffer(const touchgfx::Rect& rect)
{
    HAL::flushFrameBuffer(rect);
    // If the framebuffer is placed in Write Through cached memory (e.g. SRAM) then
    // the DCache must be flushed prior to DMA2D accessing it. That's done
    // using the function SCB_CleanInvalidateDCache(). Remember to enable "CPU Cache" in the
    // "System Core" settings for "Cortex M7" in CubeMX in order for this function call to work.
    if (SCB->CCR & SCB_CCR_DC_Msk)
    {
        SCB_CleanInvalidateDCache();
    }
}

bool TouchGFXGeneratedHAL::blockCopy(void* RESTRICT dest, const void* RESTRICT src, uint32_t numBytes)
{
    return HAL::blockCopy(dest, src, numBytes);
}

void TouchGFXGeneratedHAL::InvalidateCache()
{
    // If the framebuffer is placed in Write Through cached memory (e.g. SRAM) then
    // the DCache must be flushed prior to DMA2D accessing it. That's done
    // using the function SCB_CleanInvalidateDCache(). Remember to enable "CPU Cache" in the
    // "System Core" settings for "Cortex M7" in CubeMX in order for this function call to work.
    if (SCB->CCR & SCB_CCR_DC_Msk)
    {
        SCB_CleanInvalidateDCache();
    }
}

void TouchGFXGeneratedHAL::FlushCache()
{
    // If the framebuffer is placed in Write Through cached memory (e.g. SRAM) then
    // the DCache must be flushed prior to DMA2D accessing it. That's done
    // using the function SCB_CleanInvalidateDCache(). Remember to enable "CPU Cache" in the
    // "System Core" settings for "Cortex M7" in CubeMX in order for this function call to work.
    if (SCB->CCR & SCB_CCR_DC_Msk)
    {
        SCB_CleanInvalidateDCache();
    }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
