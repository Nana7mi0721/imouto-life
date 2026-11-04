
undefined4 FUN_0054fe20(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int *piVar5;
  int iVar6;
  int local_8;
  
  iVar1 = DAT_00a74b80;
  if (DAT_00a72a60 != 0) {
    puVar4 = &DAT_00a74b84;
    iVar2 = FUN_00550060(0);
    local_8 = 0;
    if (0 < iVar1) {
      do {
        iVar6 = 0;
        piVar5 = (int *)(puVar4 + 0x14);
        do {
          iVar3 = FUN_0056b270(puVar4,iVar6);
          if ((((iVar3 != 0) && (piVar5[-4] != 0)) && (-1 < piVar5[-2])) && (iVar2 != *piVar5)) {
            if (iVar2 < *piVar5) {
              *piVar5 = iVar2;
            }
            iVar3 = *piVar5;
            *piVar5 = iVar2;
            piVar5[-1] = piVar5[-1] + (iVar2 - iVar3);
            if (piVar5[-2] <= piVar5[-1]) {
              FUN_0054fd70(local_8 + 1,iVar6);
            }
          }
          iVar6 = iVar6 + 1;
          piVar5 = piVar5 + 8;
        } while (iVar6 < 2);
        local_8 = local_8 + 1;
        puVar4 = puVar4 + 0x4d4;
      } while (local_8 < iVar1);
    }
    if (DAT_00a72a60 != 0) {
      FUN_0056af40();
    }
  }
  return 0;
}

