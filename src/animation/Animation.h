#ifndef __ANIMATION_H__
#define __ANIMATION_H__

class Animation{
    protected:
        bool running;
    public:
        Animation(bool running = false) : running(running) {}

        virtual void play() = 0;
        virtual void update() = 0;

        virtual void stop() {
            this->running = false;
        }

        bool isRunning() const {
            return this->running;
        }
};

#endif