
void __thiscall
FUN_004a5370(int param_1,int *param_2,int *param_3,undefined4 *param_4,undefined4 *param_5,
            undefined4 *param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
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
      uVar4 = *param_6;
      uVar3 = *param_5;
      uVar2 = *param_4;
      FUN_004d31e0(local_8);
      FUN_004a5440(uVar2,uVar3,uVar4);
    }
    local_8 = local_8 + 1;
  } while( true );
}

