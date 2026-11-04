
undefined4 FUN_00666e40(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x240);
  if (*(int *)(iVar1 + 0x98) == 0) {
    (**(code **)(param_1 + 0x204))(param_1);
  }
  *(undefined2 *)(iVar1 + 0x40) = 9;
  *(undefined2 *)(iVar1 + 0x42) = 0x1ff;
  *(undefined2 *)(iVar1 + 0x44) = 0x102;
  *(undefined4 *)(iVar1 + 0x4c) = 0;
  *(undefined4 *)(iVar1 + 0x48) = 0;
  *(undefined4 *)(iVar1 + 0x84) = 10000;
  *(undefined4 *)(iVar1 + 0x88) = 0;
  *(undefined4 *)(iVar1 + 0x8c) = 0;
  *(undefined4 *)(iVar1 + 0x90) = 0;
  *(int *)(iVar1 + 0x94) = *(int *)(param_1 + 0x250) + -5 + *(int *)(param_1 + 0x24c);
  FUN_00667370(iVar1);
  *(undefined4 *)(iVar1 + 0x80) = 0xffff;
  return 1;
}

