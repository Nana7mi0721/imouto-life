
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setmbcp_lk
   
   Library: Visual Studio 2003 Release */

undefined4 __setmbcp_lk(UINT param_1)

{
  BYTE *pBVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  BOOL BVar5;
  BYTE *pBVar6;
  int iVar7;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  uint local_20;
  _cpinfo local_1c;
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  if (param_1 != 0) {
    iVar8 = 0;
    uVar4 = 0;
    do {
      if (*(UINT *)((int)&DAT_0084bc58 + uVar4) == param_1) {
        puVar11 = (undefined4 *)&DAT_00f48920;
        for (iVar7 = 0x40; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar11 = 0;
          puVar11 = puVar11 + 1;
        }
        local_20 = 0;
        *(undefined1 *)puVar11 = 0;
        pbVar9 = (byte *)(iVar8 * 0x30 + 0x84bc68);
        do {
          bVar3 = *pbVar9;
          pbVar10 = pbVar9;
          while ((bVar3 != 0 && (bVar2 = pbVar10[1], bVar2 != 0))) {
            uVar4 = (uint)bVar3;
            if (uVar4 <= bVar2) {
              bVar3 = (&DAT_0084bc50)[local_20];
              do {
                (&DAT_00f48921)[uVar4] = (&DAT_00f48921)[uVar4] | bVar3;
                uVar4 = uVar4 + 1;
              } while (uVar4 <= bVar2);
            }
            pbVar10 = pbVar10 + 2;
            bVar3 = *pbVar10;
          }
          local_20 = local_20 + 1;
          pbVar9 = pbVar9 + 8;
        } while (local_20 < 4);
        DAT_00f48a24 = param_1;
        DAT_00f48900 = 1;
        DAT_00f488f8 = _CPtoLCID();
        _DAT_00f48a30 = *(undefined4 *)(&DAT_0084bc5c + extraout_ECX);
        DAT_00f48a34 = *(undefined4 *)(&DAT_0084bc60 + extraout_ECX);
        DAT_00f48a38 = *(undefined4 *)(&DAT_0084bc64 + extraout_ECX);
        goto LAB_005047de;
      }
      uVar4 = uVar4 + 0x30;
      iVar8 = iVar8 + 1;
    } while (uVar4 < 0xf0);
    BVar5 = GetCPInfo(param_1,&local_1c);
    if (BVar5 == 1) {
      puVar11 = (undefined4 *)&DAT_00f48920;
      for (iVar8 = 0x40; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar11 = 0;
        puVar11 = puVar11 + 1;
      }
      *(undefined1 *)puVar11 = 0;
      DAT_00f48a24 = param_1;
      DAT_00f488f8 = 0;
      if (local_1c.MaxCharSize < 2) {
        DAT_00f48900 = 0;
      }
      else {
        if (local_1c.LeadByte[0] != '\0') {
          pBVar6 = local_1c.LeadByte + 1;
          do {
            bVar3 = *pBVar6;
            if (bVar3 == 0) break;
            for (uVar4 = (uint)pBVar6[-1]; uVar4 <= bVar3; uVar4 = uVar4 + 1) {
              (&DAT_00f48921)[uVar4] = (&DAT_00f48921)[uVar4] | 4;
            }
            pBVar1 = pBVar6 + 1;
            pBVar6 = pBVar6 + 2;
          } while (*pBVar1 != 0);
        }
        uVar4 = 1;
        do {
          (&DAT_00f48921)[uVar4] = (&DAT_00f48921)[uVar4] | 8;
          uVar4 = uVar4 + 1;
        } while (uVar4 < 0xff);
        DAT_00f488f8 = _CPtoLCID();
        DAT_00f48900 = extraout_ECX_00;
      }
      _DAT_00f48a30 = 0;
      DAT_00f48a34 = 0;
      DAT_00f48a38 = 0;
      goto LAB_005047de;
    }
    if (DAT_00a1fdc4 == 0) {
      return 0xffffffff;
    }
  }
  setSBCS();
LAB_005047de:
  setSBUpLow();
  return 0;
}

