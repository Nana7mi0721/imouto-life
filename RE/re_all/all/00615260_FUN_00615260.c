
void __fastcall FUN_00615260(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0xc);
  iVar2 = *(int *)(param_1 + 0x24);
  if (iVar2 < iVar6) {
    iVar4 = *(int *)(param_1 + 0x24);
    if ((iVar4 <= iVar6) && (iVar4 < iVar6)) {
      FUN_0078e010(iVar6);
      do {
        puVar1 = (undefined4 *)(*(int *)(param_1 + 0x2c) + iVar4 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          *puVar1 = 0;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar6);
    }
    *(int *)(param_1 + 0x24) = iVar6;
    iVar4 = *(int *)(param_1 + 0x38);
    if ((iVar4 <= iVar6) && (iVar4 < iVar6)) {
      FUN_0078e010(iVar6);
      do {
        puVar1 = (undefined4 *)(*(int *)(param_1 + 0x40) + iVar4 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          *puVar1 = 0;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar6);
    }
    iVar4 = 0;
    *(int *)(param_1 + 0x38) = iVar6;
    if (0 < iVar6) {
      do {
        iVar4 = iVar4 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x2c) + -4 + iVar4 * 4) = 0xffffffff;
      } while (iVar4 < iVar6);
    }
    iVar4 = 0;
    if (0 < iVar6) {
      do {
        iVar4 = iVar4 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x40) + -4 + iVar4 * 4) = 0xffffffff;
      } while (iVar4 < iVar6);
    }
    iVar6 = 0;
    if (0 < iVar2) {
      iVar4 = 0;
      do {
        piVar5 = (int *)(iVar4 + *(int *)(param_1 + 0x10));
        iVar4 = iVar4 + 0x10;
        uVar3 = *(int *)(piVar5[1] + 0xc) << 0x10 | *(uint *)(*piVar5 + 0xc);
        uVar3 = uVar3 + ~(uVar3 << 0xf);
        uVar3 = ((int)uVar3 >> 10 ^ uVar3) * 9;
        uVar3 = uVar3 ^ (int)uVar3 >> 6;
        uVar3 = uVar3 + ~(uVar3 << 0xb);
        uVar3 = ((int)uVar3 >> 0x10 ^ uVar3) & *(int *)(param_1 + 0xc) - 1U;
        *(undefined4 *)(*(int *)(param_1 + 0x40) + iVar6 * 4) =
             *(undefined4 *)(*(int *)(param_1 + 0x2c) + uVar3 * 4);
        *(int *)(*(int *)(param_1 + 0x2c) + uVar3 * 4) = iVar6;
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar2);
    }
  }
  return;
}

