
uint FUN_00584470(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  bool bVar5;
  
  if (DAT_00dccde0 == '\0') {
    return 0xffffffff;
  }
  if (((((DAT_00cc6e00 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc6e28)) ||
      ((DAT_00cc6e30 <= (int)(param_1 & 0xffff) ||
       (piVar3 = *(int **)(DAT_00cc6e04 + (param_1 & 0xffff) * 4), piVar3 == (int *)0x0)))) ||
     ((*piVar3 * 0x10000 != (param_1 & 0x3ff0000) || (piVar3[4] != 0)))) {
    return 0xffffffff;
  }
  if ((param_2 < 0) || (*(int *)(piVar3[0x10] + 0xac) <= param_2)) {
    return 0xffffffff;
  }
  iVar4 = param_2 * 0xb8 + piVar3[0x6c];
  iVar1 = *(int *)(iVar4 + 8);
  if ((**(uint **)(iVar4 + 0x10) & *(uint *)(*(int *)(iVar4 + 0xc) + 0xc)) != 0) {
    FUN_005833e0(iVar4);
  }
  if (*(char *)(iVar4 + 0xa4) != '\0') goto LAB_00584591;
  iVar2 = *(int *)(iVar4 + 0xb0);
  *(undefined1 *)(iVar4 + 0xa5) = 1;
  if (iVar2 == -1) {
    iVar2 = *(int *)(iVar1 + 0x19c);
  }
  if (iVar2 == 1) {
    iVar2 = *(int *)(iVar4 + 0xb4);
    if (iVar2 == -1) {
      iVar2 = *(int *)(iVar1 + 0x1a0);
    }
    if (iVar2 == 0xff) {
      if (*(int *)(*(int *)(iVar4 + 4) + 0x18) == 0) {
        if ((*(float *)(iVar1 + 0x10) == 1.0) &&
           ((*(char *)(iVar4 + 0x5d) == '\0' || (*(float *)(iVar4 + 0x6c) == 1.0))))
        goto LAB_005845b6;
      }
      else if (*(int *)(*(int *)(iVar4 + 4) + 0x24) == 0) {
LAB_005845b6:
        if (*(float *)(iVar4 + 0xa0) == 1.0) {
          if (*(int *)(iVar1 + 0x58) == 0) {
LAB_00584601:
            *(undefined1 *)(iVar4 + 0xa5) = 0;
            *(undefined1 *)(iVar4 + 0xa4) = 1;
            return (uint)*(byte *)(iVar4 + 0xa5);
          }
          piVar3 = (int *)(*(int *)(iVar1 + 100) * 0x74 + piVar3[0x6f]);
          iVar1 = *piVar3;
          if (piVar3[0x11] == 0) {
            if (piVar3[0xe] == 0) {
              if (*(int *)(iVar1 + 0x50) == 0) {
                bVar5 = *(int *)(iVar1 + 0x3c) == 0;
              }
              else {
                bVar5 = *(int *)(iVar1 + 0x60) == 0;
              }
            }
            else {
              bVar5 = piVar3[0xb] == 0;
            }
          }
          else {
            bVar5 = piVar3[0x15] == 0;
          }
          if (bVar5) goto LAB_00584601;
        }
      }
    }
  }
  *(undefined1 *)(iVar4 + 0xa4) = 1;
LAB_00584591:
  return (uint)*(byte *)(iVar4 + 0xa5);
}

