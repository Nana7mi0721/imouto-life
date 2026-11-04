
undefined4 FUN_00651ba0(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  iVar4 = FUN_0065f680(param_1);
  if ((iVar4 != 0) && (*(int *)(param_1 + 0xb0) != 0)) {
    uVar6 = *(uint *)(param_1 + 0xc);
    if ((uVar6 & 0x20000) != 0) {
LAB_00651e3e:
      uVar5 = FUN_00652450(param_1,param_2);
      return uVar5;
    }
    iVar4 = param_2 * 8;
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + iVar4);
    uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 4 + iVar4);
    if ((uVar2 == 0) && (uVar1 == 0)) {
      FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFFillStrip",
                   s_Invalid_strip_byte_count__I64u__s_00a06df8,0,0,param_2);
    }
    else {
      if (((uVar6 & 0x800) != 0) &&
         (((uVar6 & *(ushort *)(param_1 + 0x5e)) != 0 || ((uVar6 & 0x100) != 0)))) {
        if (((uVar6 & 0x200) != 0) && (*(int *)(param_1 + 0x24c) != 0)) {
          FUN_006507e0(*(int *)(param_1 + 0x24c));
          *(undefined4 *)(param_1 + 0x24c) = 0;
          *(undefined4 *)(param_1 + 0x250) = 0;
        }
        uVar8 = *(uint *)(param_1 + 0xc) & 0xfffffdff;
        *(uint *)(param_1 + 0xc) = uVar8;
        uVar6 = *(uint *)(param_1 + 0x268);
        uVar9 = (int)uVar6 >> 0x1f;
        if ((uVar2 <= uVar9) && ((uVar2 < uVar9 || (uVar1 <= uVar6)))) {
          uVar10 = (uVar9 - uVar2) - (uint)(uVar6 < uVar1);
          puVar7 = (uint *)(*(int *)(param_1 + 0xac) + iVar4);
          uVar3 = puVar7[1];
          if ((uVar3 <= uVar10) && ((uVar3 < uVar10 || (*puVar7 <= uVar6 - uVar1)))) {
            *(uint *)(param_1 + 0x250) = uVar1;
            iVar4 = *(int *)(*(int *)(param_1 + 0xac) + param_2 * 8);
            *(undefined4 *)(param_1 + 0x254) = 0;
            *(int *)(param_1 + 0x24c) = iVar4 + *(int *)(param_1 + 0x264);
            *(uint *)(param_1 + 600) = uVar1;
            *(uint *)(param_1 + 0xc) = uVar8 | 0x800000;
            uVar5 = FUN_00652450(param_1,param_2);
            return uVar5;
          }
        }
        puVar7 = (uint *)(*(int *)(param_1 + 0xac) + param_2 * 8);
        FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFFillStrip",
                     s_Read_error_on_strip__lu__got__I6_00a06dbc,param_2,uVar6 - *puVar7,
                     (uVar9 - *(int *)(*(int *)(param_1 + 0xac) + 4 + param_2 * 8)) -
                     (uint)(uVar6 < *puVar7),uVar1,uVar2);
        *(undefined4 *)(param_1 + 0x1c4) = 0xffffffff;
        return 0;
      }
      if ((int)uVar1 >> 0x1f != uVar2) {
        FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFFillStrip",s_Integer_overflow_00a06c8c);
        return 0;
      }
      if (*(int *)(param_1 + 0x250) < (int)uVar1) {
        *(undefined4 *)(param_1 + 0x1c4) = 0xffffffff;
        if ((uVar6 & 0x200) == 0) {
          FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFFillStrip",
                       s_Data_buffer_too_small_to_hold_st_00a06d94,param_2);
          return 0;
        }
        iVar4 = FUN_00652360(param_1,0,uVar1);
        if (iVar4 == 0) {
          return 0;
        }
      }
      if ((*(uint *)(param_1 + 0xc) & 0x800000) != 0) {
        *(undefined4 *)(param_1 + 0x1c4) = 0xffffffff;
        iVar4 = FUN_00652360(param_1,0,uVar1);
        if (iVar4 == 0) {
          return 0;
        }
      }
      uVar6 = FUN_00651a10(param_1,param_2,*(undefined4 *)(param_1 + 0x24c),uVar1,"TIFFFillStrip");
      if (uVar6 == uVar1) {
        *(undefined4 *)(param_1 + 0x254) = 0;
        *(uint *)(param_1 + 600) = uVar1;
        if (((*(uint *)(param_1 + 0xc) & (uint)*(ushort *)(param_1 + 0x5e)) == 0) &&
           ((*(uint *)(param_1 + 0xc) & 0x100) == 0)) {
          FUN_0065a770(*(undefined4 *)(param_1 + 0x24c),uVar1);
        }
        goto LAB_00651e3e;
      }
    }
  }
  return 0;
}

