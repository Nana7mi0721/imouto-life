
undefined4 FUN_0067aa60(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x1c), iVar1 != 0)) {
    if ((int)param_2 < 0) {
      iVar3 = 0;
      param_2 = -param_2;
    }
    else {
      iVar3 = ((int)param_2 >> 4) + 1;
      if ((int)param_2 < 0x30) {
        param_2 = param_2 & 0xf;
      }
    }
    if ((param_2 == 0) || ((7 < (int)param_2 && ((int)param_2 < 0x10)))) {
      if ((*(int *)(iVar1 + 0x34) != 0) && (*(uint *)(iVar1 + 0x24) != param_2)) {
        (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),*(int *)(iVar1 + 0x34));
        *(undefined4 *)(iVar1 + 0x34) = 0;
      }
      *(int *)(iVar1 + 8) = iVar3;
      *(uint *)(iVar1 + 0x24) = param_2;
      uVar2 = FUN_0067aa30(param_1);
      return uVar2;
    }
  }
  return 0xfffffffe;
}

