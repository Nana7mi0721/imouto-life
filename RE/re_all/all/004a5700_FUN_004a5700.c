
void __thiscall FUN_004a5700(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int local_8;
  
  FUN_0049b960(param_2,param_1 + 0x94);
  local_8 = *(int *)(param_1 + 0x94);
  do {
    iVar1 = FUN_004d3180();
    if (iVar1 <= local_8) {
      return;
    }
    iVar1 = FUN_004d31e0(local_8);
    if ((*(int *)(iVar1 + 0x26c) < *param_2) ||
       (iVar1 = FUN_004d31e0(local_8), *param_3 < *(int *)(iVar1 + 0x26c))) {
      iVar1 = FUN_004d31e0(local_8);
      if (*param_3 < *(int *)(iVar1 + 0x26c)) {
        return;
      }
    }
    else {
      FUN_004d31e0(local_8);
      FUN_004cd4c0();
      FUN_004d31e0(local_8);
      FUN_004cc250();
    }
    local_8 = local_8 + 1;
  } while( true );
}

