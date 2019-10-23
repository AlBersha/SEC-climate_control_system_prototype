#pragma once


class Interface
{
public:
	virtual int DisplayMenu();
};

class WorkerInterface : Interface {
public:
	int DisplayMenu() override;
};

class DirectorInterface : Interface {
	int DisplayMenu() override;
};