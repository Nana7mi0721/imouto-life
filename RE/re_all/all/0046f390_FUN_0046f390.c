
undefined4 __thiscall FUN_0046f390(int param_1,char param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_004cdbb0(3);
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    uVar3 = *(undefined4 *)(param_1 + 0x1420);
    FUN_004cde80(local_8);
    FUN_004cd310(uVar3);
    for (local_c = 0; local_c < *(int *)(param_1 + 0x1420); local_c = local_c + 1) {
      uVar3 = *(undefined4 *)(param_1 + 0x1424);
      iVar2 = local_c;
      FUN_004cde80(local_8);
      FUN_004cde80(iVar2);
      FUN_004ce970(uVar3);
      for (local_10 = 0; local_10 < *(int *)(param_1 + 0x1424); local_10 = local_10 + 1) {
        if (((param_2 != '\0') || (param_3 <= local_c)) || (param_4 <= local_10)) {
          iVar2 = local_c;
          iVar4 = local_10;
          FUN_004cde80(local_8);
          FUN_004cde80(iVar2);
          puVar1 = (undefined4 *)FUN_004ce990(iVar4);
          *puVar1 = 100000;
        }
      }
    }
  }
  return 1;
}

