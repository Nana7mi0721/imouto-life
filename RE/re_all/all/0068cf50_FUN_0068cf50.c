
void FUN_0068cf50(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = *(int *)(param_1 + 0x1bc);
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0xc00);
  *(int *)(iVar3 + 0x18) = iVar1;
  iVar5 = 0;
  iVar4 = 0;
  iVar3 = 0x8000;
  piVar2 = (int *)(iVar1 + 0x800);
  do {
    piVar2[-0x200] = iVar4;
    piVar2[-0x100] = iVar5;
    *piVar2 = iVar3;
    iVar3 = iVar3 + 0x1d2f;
    iVar4 = iVar4 + 0x4c8b;
    piVar2 = piVar2 + 1;
    iVar5 = iVar5 + 0x9646;
  } while (iVar3 < 0x1d91d2);
  return;
}

