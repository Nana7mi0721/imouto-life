
undefined4 FUN_00652100(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  
  iVar3 = FUN_0065f680(param_1);
  if ((iVar3 != 0) && (*(int *)(param_1 + 0xb0) != 0)) {
    uVar5 = *(uint *)(param_1 + 0xc);
    if ((uVar5 & 0x20000) != 0) {
LAB_00652341:
      uVar4 = FUN_00652520(param_1,param_2);
      return uVar4;
    }
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + param_2 * 8);
    iVar3 = param_2 * 8;
    uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 4 + iVar3);
    if ((uVar2 == 0) && (uVar1 == 0)) {
      FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFFillTile",
                   s__I64u__Invalid_tile_byte_count__t_00a06f24,0,0,param_2);
    }
    else {
      if (((uVar5 & 0x800) != 0) &&
         (((uVar5 & *(ushort *)(param_1 + 0x5e)) != 0 || ((uVar5 & 0x100) != 0)))) {
        if (((uVar5 & 0x200) != 0) && (*(int *)(param_1 + 0x24c) != 0)) {
          FUN_006507e0(*(int *)(param_1 + 0x24c));
          *(undefined4 *)(param_1 + 0x24c) = 0;
          *(undefined4 *)(param_1 + 0x250) = 0;
        }
        uVar7 = *(uint *)(param_1 + 0xc) & 0xfffffdff;
        *(uint *)(param_1 + 0xc) = uVar7;
        uVar5 = *(uint *)(param_1 + 0x268);
        uVar8 = (int)uVar5 >> 0x1f;
        if ((uVar2 <= uVar8) && ((uVar2 < uVar8 || (uVar1 <= uVar5)))) {
          uVar8 = (uVar8 - uVar2) - (uint)(uVar5 < uVar1);
          puVar6 = (uint *)(*(int *)(param_1 + 0xac) + iVar3);
          uVar2 = puVar6[1];
          if ((uVar2 <= uVar8) && ((uVar2 < uVar8 || (*puVar6 <= uVar5 - uVar1)))) {
            *(uint *)(param_1 + 0x250) = uVar1;
            iVar3 = *(int *)(*(int *)(param_1 + 0xac) + iVar3);
            *(undefined4 *)(param_1 + 0x254) = 0;
            *(int *)(param_1 + 0x24c) = iVar3 + *(int *)(param_1 + 0x264);
            *(uint *)(param_1 + 600) = uVar1;
            *(uint *)(param_1 + 0xc) = uVar7 | 0x800000;
            uVar4 = FUN_00652520(param_1,param_2);
            return uVar4;
          }
        }
        *(undefined4 *)(param_1 + 0x1ec) = 0xffffffff;
        return 0;
      }
      if ((int)uVar1 >> 0x1f != uVar2) {
        FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFFillTile",s_Integer_overflow_00a06c8c);
        return 0;
      }
      if (*(int *)(param_1 + 0x250) < (int)uVar1) {
        *(undefined4 *)(param_1 + 0x1ec) = 0xffffffff;
        if ((uVar5 & 0x200) == 0) {
          FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFFillTile",
                       s_Data_buffer_too_small_to_hold_ti_00a06efc,param_2);
          return 0;
        }
        iVar3 = FUN_00652360(param_1,0,uVar1);
        if (iVar3 == 0) {
          return 0;
        }
      }
      if ((*(uint *)(param_1 + 0xc) & 0x800000) != 0) {
        *(undefined4 *)(param_1 + 0x1ec) = 0xffffffff;
        iVar3 = FUN_00652360(param_1,0,uVar1);
        if (iVar3 == 0) {
          return 0;
        }
      }
      uVar5 = FUN_00651f60(param_1,param_2,*(undefined4 *)(param_1 + 0x24c),uVar1,"TIFFFillTile");
      if (uVar5 == uVar1) {
        *(undefined4 *)(param_1 + 0x254) = 0;
        *(uint *)(param_1 + 600) = uVar1;
        if (((*(uint *)(param_1 + 0xc) & (uint)*(ushort *)(param_1 + 0x5e)) == 0) &&
           ((*(uint *)(param_1 + 0xc) & 0x100) == 0)) {
          FUN_0065a770(*(undefined4 *)(param_1 + 0x24c),uVar1);
        }
        goto LAB_00652341;
      }
    }
  }
  return 0;
}

