
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    ___strgtold12
   
   Library: Visual Studio 2003 Release */

uint __cdecl
___strgtold12(_LDBL12 *pld12,char **p_end_ptr,char *str,int mult12,int scale,int decpt,
             int implicit_E)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  ushort uVar4;
  int iVar5;
  byte bVar6;
  undefined4 uVar7;
  char *pcVar8;
  byte *pbVar9;
  int local_58;
  int local_50;
  uint local_4c;
  byte *local_44;
  int local_40;
  uint local_3c;
  char local_34 [23];
  char local_1d;
  undefined2 local_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  undefined4 local_12;
  ushort local_e;
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  iVar5 = 0;
  pcVar8 = local_34;
  uVar4 = 0;
  local_50 = 1;
  local_3c = 0;
  bVar1 = false;
  bVar3 = false;
  bVar2 = false;
  local_58 = 0;
  local_40 = 0;
  local_4c = 0;
  local_44 = (byte *)str;
  for (; (((bVar6 = *str, bVar6 == 0x20 || (bVar6 == 9)) || (bVar6 == 10)) || (bVar6 == 0xd));
      str = str + 1) {
  }
LAB_0050b52f:
  bVar6 = *str;
  pbVar9 = (byte *)(str + 1);
  switch(iVar5) {
  case 0:
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {
      if (bVar6 == DAT_0084be64) goto LAB_0050b55b;
      if (bVar6 == 0x2b) {
        uVar4 = 0;
        iVar5 = 2;
        str = (char *)pbVar9;
      }
      else if (bVar6 == 0x2d) {
        iVar5 = 2;
        uVar4 = 0x8000;
        str = (char *)pbVar9;
      }
      else {
        if (bVar6 != 0x30) goto LAB_0050b72b;
LAB_0050b619:
        iVar5 = 1;
        str = (char *)pbVar9;
      }
    }
    else {
LAB_0050b54c:
      iVar5 = 3;
LAB_0050b76d:
      str = (char *)(pbVar9 + -1);
    }
    goto LAB_0050b52f;
  case 1:
    iVar5 = 1;
    bVar1 = true;
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) goto LAB_0050b54c;
    if (bVar6 == DAT_0084be64) goto LAB_0050b5ad;
    if ((bVar6 == 0x2b) || (bVar6 == 0x2d)) goto LAB_0050b5ee;
    str = (char *)pbVar9;
    if (bVar6 == 0x30) goto LAB_0050b52f;
LAB_0050b5c7:
    bVar1 = true;
    if (((char)bVar6 < 'D') || (('E' < (char)bVar6 && (((char)bVar6 < 'd' || ('e' < (char)bVar6)))))
       ) goto LAB_0050b727;
    iVar5 = 6;
    break;
  case 2:
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) goto LAB_0050b54c;
    if (bVar6 != DAT_0084be64) {
      if (bVar6 == 0x30) goto LAB_0050b619;
      goto LAB_0050b779;
    }
LAB_0050b55b:
    iVar5 = 5;
    break;
  case 3:
    while (iVar5 = _isdigit((uint)bVar6), iVar5 != 0) {
      if (local_3c < 0x19) {
        local_3c = local_3c + 1;
        *pcVar8 = bVar6 - 0x30;
        pcVar8 = pcVar8 + 1;
      }
      else {
        local_40 = local_40 + 1;
      }
      bVar6 = *pbVar9;
      pbVar9 = pbVar9 + 1;
    }
    if (bVar6 != DAT_0084be64) goto LAB_0050b69d;
LAB_0050b5ad:
    bVar1 = true;
    iVar5 = 4;
    break;
  case 4:
    bVar3 = true;
    if (local_3c == 0) {
      while (bVar6 == 0x30) {
        local_40 = local_40 + -1;
        bVar6 = *pbVar9;
        pbVar9 = pbVar9 + 1;
      }
    }
    while (iVar5 = _isdigit((uint)bVar6), iVar5 != 0) {
      if (local_3c < 0x19) {
        local_3c = local_3c + 1;
        *pcVar8 = bVar6 - 0x30;
        pcVar8 = pcVar8 + 1;
        local_40 = local_40 + -1;
      }
      bVar6 = *pbVar9;
      pbVar9 = pbVar9 + 1;
    }
LAB_0050b69d:
    if ((bVar6 != 0x2b) && (bVar6 != 0x2d)) goto LAB_0050b5c7;
LAB_0050b5ee:
    bVar1 = true;
    pbVar9 = pbVar9 + -1;
    iVar5 = 0xb;
    break;
  case 5:
    bVar3 = true;
    iVar5 = _isdigit((uint)bVar6);
    if (iVar5 != 0) {
      iVar5 = 4;
      goto LAB_0050b76d;
    }
    goto LAB_0050b779;
  case 6:
    str = str + -1;
    local_44 = (byte *)str;
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) {
LAB_0050b76b:
      iVar5 = 9;
      goto LAB_0050b76d;
    }
    if (bVar6 == 0x2b) goto LAB_0050b7a2;
    if (bVar6 == 0x2d) goto LAB_0050b796;
    if (bVar6 != 0x30) goto LAB_0050b72b;
LAB_0050b705:
    iVar5 = 8;
    break;
  case 7:
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) goto LAB_0050b76b;
    if (bVar6 == 0x30) goto LAB_0050b705;
LAB_0050b779:
    str = (char *)local_44;
    goto LAB_0050b72b;
  case 8:
    bVar2 = true;
    while (bVar6 == 0x30) {
      bVar6 = *pbVar9;
      pbVar9 = pbVar9 + 1;
    }
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) goto LAB_0050b76b;
LAB_0050b727:
    str = (char *)(pbVar9 + -1);
    goto LAB_0050b72b;
  case 9:
    bVar2 = true;
    local_58 = 0;
    goto LAB_0050b7e9;
  default:
    goto switchD_0050b53b_caseD_a;
  case 0xb:
    if (implicit_E == 0) {
      iVar5 = 10;
      pbVar9 = (byte *)str;
      goto switchD_0050b53b_caseD_a;
    }
    local_44 = (byte *)str;
    if (bVar6 != 0x2b) {
      if (bVar6 != 0x2d) goto LAB_0050b72b;
LAB_0050b796:
      local_50 = -1;
      iVar5 = 7;
      str = (char *)pbVar9;
      goto LAB_0050b52f;
    }
LAB_0050b7a2:
    iVar5 = 7;
  }
  str = (char *)pbVar9;
  goto LAB_0050b52f;
switchD_0050b53b_caseD_a:
  str = (char *)pbVar9;
  if (iVar5 == 10) goto LAB_0050b72b;
  goto LAB_0050b52f;
LAB_0050b7e9:
  iVar5 = _isdigit((uint)bVar6);
  if (iVar5 == 0) goto LAB_0050b80c;
  local_58 = (char)bVar6 + -0x30 + local_58 * 10;
  if (0x1450 < local_58) {
    local_58 = 0x1451;
    goto LAB_0050b80c;
  }
  bVar6 = *pbVar9;
  pbVar9 = pbVar9 + 1;
  goto LAB_0050b7e9;
LAB_0050b80c:
  while( true ) {
    iVar5 = _isdigit((uint)bVar6);
    if (iVar5 == 0) break;
    bVar6 = *pbVar9;
    pbVar9 = pbVar9 + 1;
  }
  str = (char *)(pbVar9 + -1);
LAB_0050b72b:
  *p_end_ptr = str;
  if (bVar1) {
    if (0x18 < local_3c) {
      if ('\x04' < local_1d) {
        local_1d = local_1d + '\x01';
      }
      pcVar8 = pcVar8 + -1;
      local_40 = local_40 + 1;
      local_3c = 0x18;
    }
    if (local_3c != 0) {
      while (pcVar8 = pcVar8 + -1, *pcVar8 == '\0') {
        local_3c = local_3c - 1;
        local_40 = local_40 + 1;
      }
      ___mtold12(local_34,local_3c,&local_18);
      if (local_50 < 0) {
        local_58 = -local_58;
      }
      local_58 = local_58 + local_40;
      if (!bVar2) {
        local_58 = local_58 + scale;
      }
      if (!bVar3) {
        local_58 = local_58 - decpt;
      }
      if (0x1450 < local_58) {
        uVar7 = 0;
        local_e = 0x7fff;
        local_12 = 0x80000000;
        local_18 = 0;
        local_4c = 2;
        goto LAB_0050b8b9;
      }
      if (-0x1451 < local_58) {
        ___multtenpow12(&local_18,local_58,mult12);
        uVar7 = CONCAT22(uStack_14,uStack_16);
        goto LAB_0050b8b9;
      }
      local_4c = 1;
    }
  }
  else {
    local_4c = 4;
  }
  local_18 = 0;
  local_e = 0;
  local_12 = 0;
  uVar7 = 0;
LAB_0050b8b9:
  *(undefined4 *)(pld12->ld12 + 6) = local_12;
  *(undefined4 *)(pld12->ld12 + 2) = uVar7;
  *(ushort *)(pld12->ld12 + 10) = local_e | uVar4;
  *(undefined2 *)pld12->ld12 = local_18;
  return local_4c;
}

