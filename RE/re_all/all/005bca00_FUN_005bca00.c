
int FUN_005bca00(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char **ppcVar5;
  int *piVar6;
  char **ppcVar7;
  char *local_720 [2];
  int local_718;
  undefined4 local_714;
  int local_710;
  undefined4 local_70c;
  undefined4 local_708;
  undefined4 *local_704;
  char *local_700 [8];
  undefined4 local_6e0;
  undefined4 local_6dc;
  undefined4 local_6d8;
  undefined4 local_6d4;
  undefined4 local_6d0;
  undefined4 local_6cc;
  char *local_6c8;
  undefined4 local_6c4;
  undefined4 local_6c0;
  undefined4 local_6bc;
  undefined4 local_6b8;
  undefined4 local_6b4;
  undefined4 local_6b0;
  char *local_6ac;
  undefined4 local_6a8;
  undefined4 local_6a4;
  undefined4 local_6a0;
  undefined4 local_69c;
  undefined4 local_698;
  undefined4 local_694;
  char *local_690;
  undefined4 local_68c;
  undefined4 local_688;
  undefined4 local_684;
  undefined4 local_680;
  undefined4 local_67c;
  undefined4 local_678;
  char *local_674;
  undefined4 local_670;
  undefined4 local_66c;
  undefined4 local_668;
  undefined4 local_664;
  undefined4 local_660;
  undefined4 local_65c;
  char *local_658 [7];
  int local_63c [399];
  
  local_6c0 = 0x1c;
  local_6a4 = 0x1c;
  local_69c = 0x1c;
  local_690 = "TEXCOORD";
  local_674 = "TEXCOORD";
  local_6c8 = "COLOR";
  local_6ac = "COLOR";
  iVar4 = 6;
  local_700[0] = "POSITION";
  local_700[1] = (char *)0x0;
  local_700[2] = (char *)0x6;
  local_700[3] = (char *)0x0;
  local_700[4] = (char *)0x0;
  local_700[5] = (char *)0x0;
  local_700[6] = (char *)0x0;
  local_700[7] = "NORMAL";
  local_6e0 = 0;
  local_6dc = 6;
  local_6d8 = 0;
  local_6d4 = 0xc;
  local_6d0 = 0;
  local_6cc = 0;
  local_6c4 = 0;
  local_6bc = 0;
  local_6b8 = 0x18;
  local_6b4 = 0;
  local_6b0 = 0;
  local_6a8 = 1;
  local_6a0 = 0;
  local_698 = 0;
  local_694 = 0;
  local_68c = 0;
  local_688 = 2;
  local_684 = 0;
  local_680 = 0x20;
  local_67c = 0;
  local_678 = 0;
  local_670 = 1;
  local_66c = 2;
  local_668 = 0;
  local_664 = 0x30;
  local_660 = 0;
  local_65c = 0;
  _memset(local_700 + 0x2a,0,0x658);
  if (DAT_00f3a070 == 0) {
    return -1;
  }
  iVar1 = param_2 + param_1 * 3;
  local_704 = &DAT_00ef72b0 + iVar1;
  if ((&DAT_00ef72b0)[iVar1] != 0) {
    return 0;
  }
  iVar1 = 0x40;
  if (param_1 != 0) {
    local_718 = 6;
    local_710 = 0x40;
    local_720[0] = "TANGENT";
    local_720[1] = (char *)0x0;
    local_714 = 0;
    local_70c = 0;
    local_708 = 0;
    ppcVar5 = local_720;
    ppcVar7 = local_700 + 0x2a;
    for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
      *ppcVar7 = *ppcVar5;
      ppcVar5 = ppcVar5 + 1;
      ppcVar7 = ppcVar7 + 1;
    }
    local_718 = 6;
    iVar4 = 8;
    local_720[0] = "BINORMAL";
    local_720[1] = (char *)0x0;
    local_714 = 0;
    local_710 = 0x4c;
    local_70c = 0;
    local_708 = 0;
    ppcVar5 = local_720;
    piVar6 = local_63c;
    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar6 = (int)*ppcVar5;
      ppcVar5 = ppcVar5 + 1;
      piVar6 = piVar6 + 1;
    }
    iVar1 = 0x58;
  }
  iVar2 = iVar4;
  if ((0 < param_2) && (param_2 < 3)) {
    local_710 = iVar1;
    local_720[0] = "BLENDINDICES";
    local_720[1] = (char *)0x0;
    local_718 = 0x1e;
    local_714 = 0;
    local_70c = 0;
    local_708 = 0;
    ppcVar5 = local_720;
    ppcVar7 = local_700 + iVar4 * 7;
    for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppcVar7 = *ppcVar5;
      ppcVar5 = ppcVar5 + 1;
      ppcVar7 = ppcVar7 + 1;
    }
    local_710 = iVar1 + 4;
    iVar2 = iVar4 + 2;
    local_720[0] = "BLENDWEIGHT";
    local_720[1] = (char *)0x0;
    local_718 = 2;
    local_714 = 0;
    local_70c = 0;
    local_708 = 0;
    ppcVar5 = local_720;
    ppcVar7 = local_700 + (iVar4 + 1) * 7;
    for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
      *ppcVar7 = *ppcVar5;
      ppcVar5 = ppcVar5 + 1;
      ppcVar7 = ppcVar7 + 1;
    }
    if (param_2 == 2) {
      local_710 = iVar1 + 0x14;
      local_720[0] = "BLENDINDICES";
      local_720[1] = (char *)0x1;
      local_718 = 0x1e;
      local_714 = 0;
      local_70c = 0;
      local_708 = 0;
      ppcVar5 = local_720;
      ppcVar7 = local_700 + iVar2 * 7;
      for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
        *ppcVar7 = *ppcVar5;
        ppcVar5 = ppcVar5 + 1;
        ppcVar7 = ppcVar7 + 1;
      }
      local_720[0] = "BLENDWEIGHT";
      local_720[1] = (char *)0x1;
      local_718 = param_2;
      local_714 = 0;
      local_710 = iVar1 + 0x18;
      local_70c = 0;
      local_708 = 0;
      ppcVar5 = local_720;
      ppcVar7 = local_700 + (iVar4 + 3) * 7;
      for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppcVar7 = *ppcVar5;
        ppcVar5 = ppcVar5 + 1;
        ppcVar7 = ppcVar7 + 1;
      }
      iVar2 = iVar4 + 4;
    }
  }
  param_1 = param_1 + param_2 * 2;
  if ((&DAT_00ef55bc)[param_1 * 0x50] == 0) {
    iVar4 = FUN_005b83c0(&DAT_00f2b108 + param_1 * 0xa0,&DAT_00ef55bc + param_1 * 0x50,1);
    if (iVar4 != 0) {
      FUN_0056bca0(&DAT_007fd728);
      return -1;
    }
  }
  iVar4 = FUN_005d28a0(local_700,iVar2,(&DAT_00f2b108)[param_1 * 0xa0],
                       (&DAT_00f2b10c)[param_1 * 0xa0],local_704);
  return -(uint)(iVar4 != 0);
}

