
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005bd880(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  float local_10;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  if (DAT_00f3a070 != 0) {
    iVar3 = 0;
    if (0 < DAT_00a37da8) {
      do {
        uVar1 = (&DAT_00a38120)[iVar3];
        if (uVar1 != 0) {
          iVar5 = 0;
          piVar4 = (int *)0x0;
          if ((((((DAT_00cc47d0 != 0) && (-1 < (int)uVar1)) &&
                ((uVar1 & 0x7c000000) == DAT_00cc47f8)) &&
               (((int)(uVar1 & 0xffff) < DAT_00cc4800 &&
                (piVar4 = *(int **)(DAT_00cc47d4 + (uVar1 & 0xffff) * 4), piVar4 != (int *)0x0))))
              && ((*piVar4 * 0x10000 == (uVar1 & 0x3ff0000) && (piVar4[4] == 0)))) || (iVar3 == 0))
          {
            if (((DAT_00cc79c0 != 0) && (-1 < (int)uVar1)) &&
               (((uVar1 & 0x7c000000) == DAT_00cc79e8 && ((int)(uVar1 & 0xffff) < DAT_00cc79f0)))) {
              iVar5 = *(int *)(DAT_00cc79c4 + (uVar1 & 0xffff) * 4);
            }
            FUN_00568ca0(0);
            if (DAT_00dda46c != 0) {
              FUN_00584d70();
            }
            if (iVar5 == 0) {
              if (piVar4 == (int *)0x0) {
                if ((&DAT_00a38120)[iVar3] == -6) {
                  uVar2 = (&DAT_00f1388c)[iVar3];
                }
                else {
                  uVar2 = DAT_00ef1b5c;
                  if (DAT_00ef1b58 == 0) {
                    uVar2 = DAT_00ee9bc4;
                  }
                }
              }
              else {
                uVar2 = *(undefined4 *)
                         (*(int *)(*(int *)(piVar4[0x13] + 0x3c) + 0xc) +
                         ((&DAT_00a38140)[iVar3] * *(int *)(piVar4[0x13] + 0x34) +
                         (&DAT_00a38160)[iVar3]) * 4);
              }
            }
            else {
              uVar2 = *(undefined4 *)(*(int *)(iVar5 + 0x450) + 8);
            }
            local_8 = (float)_DAT_0081ec30;
            local_10 = (float)DAT_00a37ed8 / local_8;
            local_c = (float)DAT_00a37edc / local_8;
            local_8 = (float)DAT_00a37ee0 / local_8;
            local_4 = 0;
            FUN_005d5380(uVar2,&local_10,0);
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < DAT_00a37da8);
    }
    FUN_005d53d0(DAT_00f138dc,1,0x3f800000,0,0);
  }
  return 0;
}

