
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_006c744e(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  double in_XMM0_Qa;
  double dVar4;
  double dVar5;
  double dVar6;
  ushort uStack_c;
  undefined6 uStack_a;
  ushort uStack_4;
  
  uVar1 = (ushort)((ulonglong)in_XMM0_Qa >> 0x30) & 0x7fff;
  if ((0x408f - uVar1 | uVar1 - 0x3c90) < 0x80000000) {
    dVar5 = _DAT_00836130 * in_XMM0_Qa + _DAT_00836110;
    dVar6 = (_UNK_00836138 * in_XMM0_Qa + _UNK_00836118) - _UNK_00836118;
    uVar1 = SUB84(dVar5,0);
    iVar2 = (uVar1 & 0x3f) * 0x10;
    dVar4 = (in_XMM0_Qa - _DAT_00836140 * (dVar5 - _DAT_00836110)) -
            _DAT_00836150 * (dVar5 - _DAT_00836110);
    dVar6 = (in_XMM0_Qa - _UNK_00836148 * dVar6) - _UNK_00836158 * dVar6;
    dVar5 = (double)(*(ulonglong *)(&UNK_00836188 + iVar2) |
                    ((ulonglong)dVar5 & _DAT_008360f0) + _DAT_00836100 << 0x2e);
    dVar4 = dVar6 * dVar6 * (_UNK_00836178 + _UNK_00836168 * dVar6) +
            dVar4 + *(double *)(&DAT_00836180 + iVar2) +
            dVar4 * dVar4 * dVar4 * dVar4 * (_DAT_00836170 + _DAT_00836160 * dVar4);
    if (((int)uVar1 >> 6) + 0x37eU < 0x77d) {
      return (float10)(dVar4 * dVar5 + dVar5);
    }
    uStack_4 = (ushort)((~_DAT_008360e0 & (ulonglong)dVar5) >> 0x30) |
               (ushort)(((ulonglong)(((int)uVar1 >> 7) + 0x3ff) << 0x34) >> 0x30);
    uStack_a = (undefined6)(~_DAT_008360e0 & (ulonglong)dVar5);
    in_XMM0_Qa = (double)((ulonglong)((((int)uVar1 >> 6) - ((int)uVar1 >> 7)) + 0x3ff) << 0x34) *
                 ((double)CONCAT26(uStack_4,uStack_a) + dVar4 * (double)CONCAT26(uStack_4,uStack_a))
    ;
    uStack_c = (ushort)((ulonglong)in_XMM0_Qa >> 0x30);
    if ((uStack_c & 0x7ff0) < 0x7ff0) {
      if (((ulonglong)in_XMM0_Qa & 0x7ff0000000000000) != 0) goto LAB_006c7642;
      uVar3 = 0xf;
    }
    else {
      uVar3 = 0xe;
    }
  }
  else {
    uVar1 = param_2 & 0x7fffffff;
    if (uVar1 < 0x40900000) {
      return (float10)((double)CONCAT44(param_2,param_1) + _DAT_00836580);
    }
    if (uVar1 < 0x7ff00000) {
      if (param_2 < 0x80000000) {
        in_XMM0_Qa = DAT_008365b0 * DAT_008365b0;
        uVar3 = 0xe;
      }
      else {
        in_XMM0_Qa = DAT_008365b8 * DAT_008365b8;
        uVar3 = 0xf;
      }
    }
    else {
      if ((uVar1 < 0x7ff00001) && (param_1 == 0)) {
        if (param_2 == 0x7ff00000) {
          return (float10)_DAT_008365a0;
        }
        return (float10)_DAT_008365a8;
      }
      uVar3 = 0x3ea;
    }
  }
  uStack_c = SUB82(in_XMM0_Qa,0);
  uStack_a = (undefined6)((ulonglong)in_XMM0_Qa >> 0x10);
  ___libm_error_support(&param_1,&param_1,(short)&uStack_c,uVar3);
  in_XMM0_Qa = (double)CONCAT62(uStack_a,uStack_c);
LAB_006c7642:
  return (float10)in_XMM0_Qa;
}

