
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_006c770e(double param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  undefined1 in_XMM0 [16];
  double dVar9;
  double dVar10;
  double dVar11;
  double local_c;
  
  iVar4 = 0;
  while( true ) {
    uVar2 = (uint)(ushort)(in_XMM0._6_2_ >> 4);
    dVar7 = (double)(in_XMM0._0_8_ & (ulonglong)_DAT_008365d0 | (ulonglong)DAT_00836640);
    dVar8 = (double)(in_XMM0._0_8_ & _UNK_008365d8 | _UNK_00836648);
    uVar1 = SUB82(_DAT_008365f0 + dVar7,0) & 0x7f0;
    dVar11 = (double)(_UNK_00836608 & (ulonglong)dVar8);
    dVar10 = (double)(_DAT_00836600 & (ulonglong)dVar7) * *(double *)(&DAT_00836ae0 + uVar1) -
             _DAT_008365e0;
    dVar7 = (dVar7 - (double)(_DAT_00836600 & (ulonglong)dVar7)) *
            *(double *)(&DAT_00836ae0 + uVar1);
    dVar9 = (dVar8 - dVar11) * *(double *)(&UNK_00836ae8 + uVar1);
    dVar8 = dVar7 + dVar10;
    in_XMM0._8_8_ = dVar9 + (dVar11 * *(double *)(&UNK_00836ae8 + uVar1) - _UNK_008365e8);
    uVar3 = uVar2 - 1;
    if (uVar3 < 0x7fe) {
      iVar4 = (uVar2 - 0x3ff) + iVar4;
      dVar11 = (double)iVar4;
      iVar5 = 0;
      if (uVar1 + iVar4 * 0x400 == 0) {
        iVar5 = 0x10;
      }
      return (float10)(((_UNK_00836698 * in_XMM0._8_8_ + _UNK_008366a8) * in_XMM0._8_8_ +
                       _UNK_008366b8) * in_XMM0._8_8_ * in_XMM0._8_8_ +
                       ((_DAT_00836690 * dVar8 + _DAT_008366a0) * dVar8 + _DAT_008366b0) *
                       dVar8 * dVar8 * dVar8 * dVar8 * dVar8 + _DAT_008366c0 * dVar8 +
                       *(double *)(&UNK_008366d8 + uVar1) + dVar11 * _UNK_00836618 +
                       (double)((ulonglong)dVar9 & *(ulonglong *)(&UNK_00836628 + iVar5)) +
                      *(double *)(&DAT_008366d0 + uVar1) + dVar10 + dVar11 * _DAT_00836610 +
                      (double)((ulonglong)dVar7 & *(ulonglong *)(&DAT_00836620 + iVar5)));
    }
    local_c = (double)-(ulonglong)(_DAT_00836650 == param_1);
    if (SUB82(local_c,0) != 0) break;
    if (uVar3 != 0xffffffff) {
      if (uVar3 < 0x7ff) {
        if (DAT_00836640 ==
            (double)((ulonglong)param_1 & (ulonglong)_DAT_008365d0 | (ulonglong)DAT_00836640)) {
          return (float10)_DAT_00836678;
        }
        uVar6 = 0x3e9;
        local_c = _DAT_008365d0;
      }
      else if (((uVar2 & 0x7ff) < 0x7ff) ||
              (SUB84(param_1,0) == 0 && ((ulonglong)param_1 & 0xfffff00000000) == 0)) {
        local_c = -NAN;
        uVar6 = 9;
      }
      else {
        uVar6 = 0x3e9;
      }
      goto LAB_006c791a;
    }
    in_XMM0._0_8_ = param_1 * DAT_00836660;
    iVar4 = -0x34;
  }
  uVar6 = 8;
  local_c = DAT_00836670;
LAB_006c791a:
  ___libm_error_support(&param_1,&param_1,&local_c,uVar6);
  return (float10)local_c;
}

