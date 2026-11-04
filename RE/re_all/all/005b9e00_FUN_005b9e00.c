
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_005b9e00(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 local_4;
  
  if (DAT_00f328e4 == 0) {
    DAT_00f328e4 = 1;
    _DAT_00f324e8 = 0;
    _DAT_00f324ec = 1;
    _DAT_00f324f8 = 2;
    _DAT_00f324fc = 3;
    _DAT_00f32528 = 4;
    _DAT_00f3252c = 5;
    _DAT_00f32538 = 6;
    _DAT_00f3253c = 7;
    _DAT_00f3263c = 8;
    _DAT_00f326e8 = 9;
    _DAT_00f326ec = 10;
    _DAT_00f326f8 = 0xb;
    _DAT_00f326fc = 0xc;
    _DAT_00f32728 = 0xd;
    _DAT_00f3272c = 0xe;
    _DAT_00f32738 = 0xf;
    _DAT_00f3273c = 0x10;
    _DAT_00f3283c = 0x11;
  }
  if ((DAT_00f07680 == 0) && (DAT_00ef7324 == 0)) {
    return 0;
  }
  iVar4 = 0;
  DAT_00f07680 = 0;
  iVar3 = 0;
  piVar5 = &DAT_00f076dc;
  local_4 = param_1;
  do {
    if (((&DAT_00f07684)[iVar3] == 0) && (DAT_00ef7324 == 0)) {
      if (0 < iVar4) {
        FUN_005d2b90(iVar3 - iVar4,iVar4,&DAT_00f07a04 + (iVar3 - iVar4));
        iVar4 = 0;
      }
    }
    else {
      (&DAT_00f07684)[iVar3] = 0;
      if ((&DAT_00f07a04)[iVar3] != 0) {
        if ((&DAT_00f07a44)[iVar3] != 0) {
          FUN_005d2040((&DAT_00f07a04)[iVar3]);
        }
        (&DAT_00f07a04)[iVar3] = 0;
      }
      (&DAT_00f07a44)[iVar3] = 0;
      if ((((float)piVar5[-2] == 0.0) &&
          ((((iVar1 = piVar5[-1], iVar1 == 0x10 || (iVar1 == 2)) || (iVar1 == 1)) &&
           ((*piVar5 == 8 && ((float)piVar5[1] == 0.0)))))) &&
         (((float)piVar5[2] == 0.0 &&
          ((((float)piVar5[3] == 0.0 && ((float)piVar5[4] == 0.0)) &&
           (((float)piVar5[5] == (float)_DAT_007fd498 && ((float)piVar5[6] == (float)_DAT_007fd490))
           )))))) {
        iVar2 = 0;
        if (iVar1 != 1) {
          iVar2 = (iVar1 != 2) + 1;
        }
        iVar2 = iVar2 + (piVar5[-3] +
                        (piVar5[-4] +
                        (piVar5[-5] + *(int *)(&DAT_00f324e8 + piVar5[-6] * 4) * 6) * 6) * 6) * 3;
        if ((&DAT_00f07a84)[iVar2] == 0) {
          iVar1 = FUN_005d29d0(piVar5 + -6,&local_4);
          if (iVar1 != 0) {
            FUN_0056bca0(&PTR_PTR_007fd448);
            return 0xffffffff;
          }
          (&DAT_00f07a84)[iVar2] = local_4;
        }
        (&DAT_00f07a04)[iVar3] = (&DAT_00f07a84)[iVar2];
      }
      else {
        iVar1 = FUN_005d29d0(piVar5 + -6,&local_4);
        if (iVar1 != 0) {
          FUN_0056bca0(&PTR_PTR_007fd400);
          return 0xffffffff;
        }
        (&DAT_00f07a04)[iVar3] = local_4;
        (&DAT_00f07a44)[iVar3] = 1;
      }
      iVar4 = iVar4 + 1;
    }
    iVar3 = iVar3 + 1;
    piVar5 = piVar5 + 0xd;
  } while (iVar3 < 0x10);
  if (0 < iVar4) {
    FUN_005d2b90(iVar3 - iVar4,iVar4,&DAT_00f07a04 + (iVar3 - iVar4));
  }
  return 0;
}

