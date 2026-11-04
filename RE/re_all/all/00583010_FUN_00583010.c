
undefined4 FUN_00583010(uint param_1,int param_2)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  if (DAT_00dccde0 == '\0') {
    return 0xffffffff;
  }
  if (((((DAT_00cc6e00 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc6e28)) ||
      ((DAT_00cc6e30 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc6e04 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)))) ||
     ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || (piVar1[4] != 0)))) {
    return 0xffffffff;
  }
  if ((param_2 < 0) || (piVar1[0x7d] <= param_2)) {
    return 0xffffffff;
  }
  iVar3 = param_2 * 0x14;
  if (*(char *)(piVar1[0x7e] + iVar3) != '\0') {
    piVar5 = *(int **)(piVar1[0x7e] + iVar3 + 0x10);
    iVar6 = *piVar5;
    iVar4 = 0;
    if (0 < *(int *)(iVar6 + 0x18)) {
      piVar5 = (int *)(piVar5[3] + 4);
      do {
        if (*piVar5 != 0) {
          *(undefined1 *)(*(int *)(*piVar5 + 8) + 0x112) = 0;
          FUN_00582850();
        }
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 0x2d;
      } while (iVar4 < *(int *)(iVar6 + 0x18));
    }
    FUN_0056e1d0(*(undefined4 *)(piVar1[0x7e] + 0x10 + iVar3));
    *(undefined4 *)(piVar1[0x7e] + 0x10 + iVar3) = 0;
    *(undefined1 *)(piVar1[0x7e] + iVar3) = 0;
    puVar2 = (undefined1 *)(piVar1[0x7f] + param_2 * 0xc);
    iVar3 = *(int *)(piVar1[0x10] + 0x7c);
    if (0 < iVar3) {
      iVar6 = iVar3;
      do {
        iVar6 = iVar6 + -1;
        *(undefined4 *)(puVar2 + 8) = 0;
        *puVar2 = 0;
        puVar2 = puVar2 + piVar1[0x7d] * 0xc;
      } while (iVar6 != 0);
    }
    *(undefined1 *)(piVar1 + 0x67) = 1;
    if (0 < iVar3) {
      puVar2 = (undefined1 *)(piVar1[0x5f] + 0x210);
      do {
        if (*(int *)(*(int *)(puVar2 + -0x200) + 0x1b8) != 0) {
          *puVar2 = 1;
        }
        puVar2 = puVar2 + 0x2b8;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    piVar1[0x7c] = piVar1[0x7c] + -1;
  }
  *(undefined1 *)(piVar1 + 0x80) = 0;
  *(undefined1 *)((int)piVar1 + 0x112) = 0;
  return 0;
}

