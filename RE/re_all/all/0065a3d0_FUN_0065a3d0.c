
/* WARNING: Removing unreachable block (ram,0x0065a509) */

void FUN_0065a3d0(uint param_1)

{
  uint *puVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  longlong *plVar6;
  longlong *plVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  ulonglong uVar12;
  longlong lVar13;
  int local_1c;
  uint local_10;
  uint local_c;
  
  iVar3 = param_1;
  puVar1 = *(uint **)(param_1 + 0xb0);
  local_10 = *puVar1;
  local_c = puVar1[1];
  lVar13 = *(longlong *)puVar1;
  lVar2 = **(longlong **)(param_1 + 0xac);
  if ((*(short *)(param_1 + 0x5a) == 6) && ((*(uint *)(param_1 + 0xc) & 0x4000) == 0)) {
    uVar9 = (uint)*(ushort *)(param_1 + 0xc2);
  }
  else {
    uVar9 = 1;
  }
  uVar12 = FUN_00651670(param_1,uVar9);
  uVar4 = (uint)uVar12;
  if (((int)(uVar12 >> 0x20) == 0) && (uVar4 < 0x2001)) {
    if (uVar4 == 0) {
      return;
    }
    iVar8 = __aulldiv(0x2000,0,uVar4,0);
    param_1 = iVar8 * uVar9;
    uVar12 = __allmul(iVar8,0,uVar4,0);
  }
  else {
    param_1 = uVar9;
  }
  if (param_1 < *(uint *)(iVar3 + 100)) {
    iVar8 = (int)(uVar12 + lVar13);
    lVar13 = __aulldiv(iVar8 + -1,(int)(uVar12 + lVar13 >> 0x20) - (uint)(iVar8 == 0),uVar12);
    iVar8 = (int)lVar13;
    if ((lVar13 != 0) && ((int)((ulonglong)lVar13 >> 0x20) == 0)) {
      iVar5 = FUN_00650c00(iVar3,iVar8,8,s_for_chopped__StripByteCounts__ar_00a0a608);
      plVar6 = (longlong *)FUN_00650c00(iVar3,iVar8,8,s_for_chopped__StripOffsets__array_00a0a5e4);
      if (iVar5 != 0) {
        if (plVar6 == (longlong *)0x0) {
          FUN_006507e0(iVar5);
          return;
        }
        if (iVar8 != 0) {
          plVar7 = plVar6;
          local_1c = iVar8;
          do {
            if (CONCAT44(local_c,local_10) < uVar12) {
              uVar12 = CONCAT44(local_c,local_10);
            }
            iVar10 = (int)(uVar12 >> 0x20);
            uVar9 = (uint)uVar12;
            *(uint *)((iVar5 - (int)plVar6) + (int)plVar7) = uVar9;
            *(int *)((iVar5 - (int)plVar6) + 4 + (int)plVar7) = iVar10;
            *plVar7 = lVar2;
            lVar2 = uVar12 + lVar2;
            bVar11 = local_10 < uVar9;
            local_10 = local_10 - uVar9;
            local_c = (local_c - iVar10) - (uint)bVar11;
            plVar7 = plVar7 + 1;
            local_1c = local_1c + -1;
          } while (local_1c != 0);
        }
        *(int *)(iVar3 + 0xa8) = iVar8;
        *(int *)(iVar3 + 0xa4) = iVar8;
        FUN_0064e1d0(iVar3,0x116,param_1);
        FUN_006507e0(*(undefined4 *)(iVar3 + 0xb0));
        FUN_006507e0(*(undefined4 *)(iVar3 + 0xac));
        *(int *)(iVar3 + 0xb0) = iVar5;
        *(longlong **)(iVar3 + 0xac) = plVar6;
        *(undefined4 *)(iVar3 + 0xb4) = 1;
        return;
      }
      if (plVar6 != (longlong *)0x0) {
        FUN_006507e0(plVar6);
      }
    }
  }
  return;
}

