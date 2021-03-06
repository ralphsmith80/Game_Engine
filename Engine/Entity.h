/*
 *  Entity.h
 *  Advanced2D
 *
 *  Created by Ralph Smith on 6/20/10.
 *  Copyright 2010 Ralph Smith. All rights reserved.
 *
 */

#include "Advanced2D.h"

#ifndef __ENTITY_H__
#define __ENTITY_H__


namespace Advanced2D {
	
	enum RenderType {
		RENDER2D = 0,
		RENDER3D = 1
	};
	
	class Entity {
	private:
		int ID;
		std::string name;
		bool visible;
		bool alive;
		enum RenderType renderType;
		int objectType;
		int lifetimeLength;
		Timer lifetimeTimer;
		
	public:
		Entity(enum RenderType renderType=RENDER2D);
		virtual ~Entity() { };
		
		virtual void move() = 0;
		virtual void animate() = 0;
		virtual void draw(bool aCenter=true) = 0;
		
		void setID(int value) { ID = value; }
		int getID() { return ID; }
		
		void setRenderType(enum RenderType type) { renderType = type; }
		enum RenderType getRenderType() { return renderType; }
		
		std::string getName() { return name; }
		void setName(std::string value) { name = value; }
		
		bool getVisible() { return visible; }
		void setVisible(bool value) { visible = value; }
		
		bool getAlive() { return alive; }
		void setAlive(bool value) { alive = value; }
		
		int getLifetime() { return lifetimeLength; }
		void setLifetime(int ms) { lifetimeLength = ms; lifetimeTimer.reset(); }
		bool lifetimeExpired() { return lifetimeTimer.stopwatch(lifetimeLength); }
		
		int getObjectType() { return objectType; }
		void setObjectType(int value) { objectType = value; }
		
	};
	
};

#endif
