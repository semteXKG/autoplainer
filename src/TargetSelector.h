#ifndef target_selector_h
#define target_selector_h

#include <Arduino.h>
#include <RotaryEncoder.h>
#include <SharedData.h>

class TargetSelector {
    private:
        RotaryEncoder* encoder;
        SharedData* sharedData;
        int prevEncPosition;
        long fastRotationTill = 0;
        double lastDistance = 0;
        long currentInputPosition = 0;
        double lastValues[MAX_INPUTS];
        long lastTimestamps[MAX_INPUTS];
        void handleEncoder();
        void handleInputSelectionButton();
        void correctAccidentalInputs();
    public:
        TargetSelector(int pin1, int pin2, SharedData* sharedData);
        ~TargetSelector();
        void tick();
};

#endif