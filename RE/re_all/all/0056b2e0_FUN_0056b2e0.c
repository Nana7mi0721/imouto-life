
undefined4 FUN_0056b2e0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  
  if (((DAT_00a828ac != 0) || (iVar3 = FUN_0050e8c0(), iVar3 != 0)) && (DAT_00a828ac != -1)) {
    if (0 < DAT_00a74b80) {
      piVar5 = &DAT_00a74c3c;
      iVar3 = DAT_00a74b80;
      do {
        piVar1 = (int *)*piVar5;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0x20))(piVar1);
          iVar4 = FUN_0050e880();
          iVar2 = *(int *)*piVar5;
          if (iVar4 == 1) {
            uVar6 = 5;
          }
          else {
            uVar6 = 10;
          }
          uVar6 = FUN_0050e7c0(uVar6);
          (**(code **)(iVar2 + 0x34))(*piVar5,uVar6);
          (**(code **)(*(int *)*piVar5 + 0x1c))((int *)*piVar5);
        }
        piVar5 = piVar5 + 0x135;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    if (DAT_00a828b4 != (int *)0x0) {
      (**(code **)(*DAT_00a828b4 + 0x20))(DAT_00a828b4);
      (**(code **)(*DAT_00a828b4 + 0x1c))(DAT_00a828b4);
    }
  }
  return 0;
}

