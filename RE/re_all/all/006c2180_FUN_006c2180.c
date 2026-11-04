
/* WARNING: Removing unreachable block (ram,0x006c22bc) */
/* WARNING: Removing unreachable block (ram,0x006c22eb) */

undefined8
FUN_006c2180(uint *param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6,
            uint param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  longlong lVar17;
  longlong lVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  int iVar21;
  int iVar22;
  int local_48;
  int local_44;
  uint *local_40;
  uint local_38;
  int local_34;
  uint local_8;
  int local_4;
  
  uVar12 = param_5 - 0x10000;
  iVar8 = param_6 + -1 + (uint)(0xffff < param_5);
  if ((iVar8 <= param_4) && ((iVar8 < param_4 || (uVar12 <= param_3)))) {
    return 0xffffffffffffffff;
  }
  local_44 = 0;
  if (0 < param_2) {
    local_40 = (uint *)((int)param_1 + 0x18);
    local_38 = uVar12;
    local_34 = iVar8;
    do {
      uVar1 = local_40[1];
      uVar2 = *local_40;
      if ((-1 < (int)uVar1) && (iVar9 = FUN_006bff30(&local_8,uVar2,uVar1,48000), -1 < iVar9)) {
        uVar3 = local_40[-4];
        uVar4 = local_40[-3];
        uVar5 = local_40[-1];
        if (0 < local_44) {
          param_1 = local_40 + -9;
          local_48 = local_44;
          do {
            local_48 = local_48 + -1;
            uVar10 = param_1[2];
            uVar11 = param_1[1];
            if ((local_4 <= (int)uVar10) &&
               (((local_4 < (int)uVar10 || (local_8 <= uVar11)) && (*param_1 == uVar5)))) {
              uVar6 = param_1[-3];
              uVar7 = param_1[-2];
              iVar15 = uVar11 - uVar2;
              iVar16 = (uVar10 - uVar1) - (uint)(uVar11 < uVar2);
              lVar17 = __alldiv(uVar11,uVar10,iVar15,iVar16);
              iVar14 = uVar6 - uVar3;
              iVar9 = (uVar7 - uVar4) - (uint)(uVar6 < uVar3);
              if ((lVar17 < 1) ||
                 (lVar18 = __alldiv(uVar6 - param_3,(uVar7 - param_4) - (uint)(uVar6 < param_3),
                                    lVar17), CONCAT44(iVar9,iVar14) <= lVar18)) {
                iVar21 = iVar14;
                iVar22 = iVar9;
                uVar19 = __allmul(lVar17,iVar15,iVar16);
                uVar19 = FUN_006c23f0(uVar11 - (uint)uVar19,
                                      (uVar10 - (int)((ulonglong)uVar19 >> 0x20)) -
                                      (uint)(uVar11 < (uint)uVar19),iVar15,iVar16,iVar21,iVar22);
                uVar20 = __allmul(iVar14,iVar9,lVar17);
                uVar10 = param_7 - (uint)uVar20;
                uVar11 = uVar10 - (uint)uVar19;
                uVar13 = uVar6 + uVar11;
                iVar9 = uVar7 + ((((((int)param_7 >> 0x1f) - (int)((ulonglong)uVar20 >> 0x20)) -
                                  (uint)(param_7 < (uint)uVar20)) - (int)((ulonglong)uVar19 >> 0x20)
                                 ) - (uint)(uVar10 < (uint)uVar19)) + (uint)CARRY4(uVar6,uVar11);
                if ((param_4 < iVar9) || ((param_4 <= iVar9 && (param_3 <= uVar13)))) {
                  if ((iVar9 <= local_34) && ((iVar9 < local_34 || (uVar13 <= local_38)))) {
                    local_38 = uVar13;
                    local_34 = iVar9;
                  }
                  break;
                }
              }
            }
            param_1 = param_1 + -8;
            if (local_48 < 1) break;
          } while( true );
        }
      }
      local_44 = local_44 + 1;
      local_40 = local_40 + 8;
    } while (local_44 < param_2);
    if ((local_34 < iVar8) || ((local_34 <= iVar8 && (local_38 < uVar12)))) {
      return CONCAT44(local_34,local_38);
    }
  }
  return 0xffffffffffffffff;
}

