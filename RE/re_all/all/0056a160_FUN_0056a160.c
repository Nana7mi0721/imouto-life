
undefined4 FUN_0056a160(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  if ((DAT_00a828ac == 0) || (DAT_00a828ac == -1)) {
    return 0xffffffff;
  }
  iVar3 = 0;
  if (0 < DAT_00a74b80) {
    puVar5 = &DAT_00a74c3c;
    do {
      piVar4 = puVar5 + -0x26;
      if ((int)puVar5[-1] < 0) {
        (**(code **)(*(int *)*puVar5 + 0x20))((int *)*puVar5);
        (**(code **)(*(int *)*puVar5 + 0x30))((int *)*puVar5,0);
        iVar2 = 2;
        do {
          piVar1 = (int *)*piVar4;
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 0x20))(piVar1);
            (**(code **)(*(int *)*piVar4 + 0x2c))((int *)*piVar4);
            *piVar4 = 0;
          }
          piVar4 = piVar4 + 8;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        (**(code **)(*(int *)*puVar5 + 8))((int *)*puVar5);
        *puVar5 = 0;
        CloseHandle((HANDLE)puVar5[1]);
      }
      FUN_0056d380(puVar5 + -0x2e,0,0x4d4);
      iVar3 = iVar3 + 1;
      puVar5 = puVar5 + 0x135;
    } while (iVar3 < DAT_00a74b80);
  }
  DAT_00a74b80 = 0;
  return 0;
}

