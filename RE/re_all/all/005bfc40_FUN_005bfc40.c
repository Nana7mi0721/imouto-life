
void FUN_005bfc40(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  
  if (DAT_00f3a070 != 0) {
    iVar5 = 3;
    if (DAT_00a3ce50 < 4) {
      iVar5 = DAT_00a3ce50;
    }
    iVar7 = 0x7c;
    puVar6 = &DAT_00a380f8;
    puVar4 = (undefined4 *)(*(int *)(DAT_00ef1ba4 + 8) + 0xc);
    do {
      puVar4[-1] = 0x3f800000;
      *puVar4 = 0x3f800000;
      puVar4[1] = 0x3f800000;
      if ((((DAT_00cc79c0 == 0) || (uVar1 = *puVar6, (int)uVar1 < 0)) ||
          ((uVar1 & 0x7c000000) != DAT_00cc79e8)) ||
         (((DAT_00cc79f0 <= (int)(uVar1 & 0xffff) ||
           (piVar2 = *(int **)(DAT_00cc79c4 + (uVar1 & 0xffff) * 4), piVar2 == (int *)0x0)) ||
          ((*piVar2 * 0x10000 != (uVar1 & 0x3ff0000) || (piVar2[4] != 0)))))) {
        puVar4[-3] = 0x3f800000;
        puVar4[-2] = 0;
      }
      else {
        iVar3 = 0;
        puVar4[-3] = piVar2[0x7b];
        puVar4[-2] = piVar2[0x7d];
        if (0 < iVar5) {
          do {
            if (*(int *)(iVar7 + (&DAT_00a38e44)[(&DAT_00a3ce58)[iVar3]]) == 0) {
              if (iVar3 == 0) {
                puVar4[-1] = 0;
              }
              else if (iVar3 == 1) {
                *puVar4 = 0;
              }
              else if (iVar3 == 2) {
                puVar4[1] = 0;
              }
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < iVar5);
        }
      }
      puVar6 = puVar6 + 1;
      iVar7 = iVar7 + 4;
      puVar4 = puVar4 + 8;
    } while ((int)puVar6 < 0xa38104);
    *(undefined4 *)(DAT_00ef1ba4 + 0xc) = 1;
  }
  return;
}

