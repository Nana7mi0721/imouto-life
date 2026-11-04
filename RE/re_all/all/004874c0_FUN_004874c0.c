
undefined4 __thiscall FUN_004874c0(int param_1,int *param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  
  FUN_0049b960(param_2,param_1 + 0x94);
  cVar1 = FUN_004d31c0();
  if (cVar1 == '\0') {
    iVar2 = FUN_004d3180();
    if (iVar2 - 1U < *(uint *)(param_1 + 0x94)) {
      local_c = FUN_004d3180();
      local_c = local_c + -1;
    }
    else {
      local_c = *(int *)(param_1 + 0x94);
    }
    iVar2 = FUN_004d31e0(local_c);
    if (*(int *)(iVar2 + 0x26c) == *param_2) {
      iVar2 = *param_3;
      FUN_004d31e0(*(undefined4 *)(param_1 + 0x94));
      uVar3 = FUN_00487580(iVar2);
      return uVar3;
    }
  }
  if (*param_3 == 9) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

