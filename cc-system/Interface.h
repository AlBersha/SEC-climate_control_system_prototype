#pragma once
class Interface
{
public:
	virtual int DisplayMenu();
	virtual bool Validation(int);
};

class WorkerInterface : public Interface {
public:
	int DisplayMenu() override;
	bool Validation(int) override;
};

class DirectorInterface : public  Interface {
	int DisplayMenu() override;
	bool Validation(int) override;
};