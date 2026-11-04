
undefined4 __thiscall FUN_004d7de0(allocator<char> *param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  char *pcVar3;
  
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar2 = FUN_004e2aa0();
    if (uVar2 < param_2) {
      FID_conflict__Xran(param_1);
    }
    else {
      pcVar3 = std::allocator<char>::allocate(param_1,param_2);
      *(char **)(param_1 + 4) = pcVar3;
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
      *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 4) + param_2;
    }
    uVar1 = 1;
  }
  return uVar1;
}

