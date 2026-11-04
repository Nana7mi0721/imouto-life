
void FUN_00678b60(int param_1,int param_2,undefined4 param_3,char *param_4,char *param_5,
                 char *param_6)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  undefined1 local_460;
  undefined1 auStack_45f [83];
  undefined1 local_40c [4];
  uint local_408;
  uint local_404;
  
  iVar2 = FUN_006782a0(param_1,param_3,&local_460);
  if (iVar2 == 0) {
    FUN_00668620(param_1,s_iTXt__invalid_keyword_00a0d89c);
  }
  switch(param_2) {
  case 0:
  case 2:
    iVar7 = iVar2 + 1;
    param_2 = 1;
    auStack_45f[iVar2] = 1;
    break;
  case -1:
  case 1:
    iVar7 = iVar2 + 1;
    param_2 = 0;
    auStack_45f[iVar2] = 0;
    break;
  default:
    FUN_00668620(param_1,s_iTXt__invalid_compression_00a0d880);
    iVar7 = iVar2;
  }
  auStack_45f[iVar7] = 0;
  iVar7 = iVar7 + 2;
  if (param_4 == (char *)0x0) {
    param_4 = &DAT_00f3fa48;
  }
  uVar4 = 0xffffffff;
  pcVar8 = param_4;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  if (param_5 == (char *)0x0) {
    param_5 = &DAT_00f3fa48;
  }
  uVar5 = 0xffffffff;
  pcVar8 = param_5;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  if (param_6 == (char *)0x0) {
    param_6 = &DAT_00f3fa48;
  }
  if (0x7fffffffU - iVar7 < uVar4) {
    iVar2 = 0x7fffffff;
  }
  else {
    iVar2 = uVar4 + iVar7;
  }
  if (0x7fffffffU - iVar2 < uVar5) {
    iVar2 = 0x7fffffff;
  }
  else {
    iVar2 = iVar2 + uVar5;
  }
  uVar6 = 0xffffffff;
  pcVar8 = param_6;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_006780a0(local_40c,param_6,~uVar6 - 1);
  if (param_2 == 0) {
    if (0x7fffffffU - iVar2 < local_408) {
      FUN_00668620(param_1,s_iTXt__uncompressed_text_too_long_00a0d85c);
    }
    local_404 = local_408;
  }
  else {
    iVar3 = FUN_006780c0(param_1,0x69545874,local_40c,iVar2);
    if (iVar3 != 0) {
      FUN_00668620(param_1,*(undefined4 *)(param_1 + 0x9c));
    }
  }
  FUN_00677300(param_1,0x69545874,local_404 + iVar2);
  FUN_00677370(param_1,&local_460,iVar7);
  FUN_00677370(param_1,param_4,uVar4);
  FUN_00677370(param_1,param_5,uVar5);
  if (param_2 == 0) {
    FUN_00677370(param_1,param_6,local_408);
    FUN_006773b0(param_1);
    return;
  }
  FUN_00678240(param_1,local_40c);
  FUN_006773b0(param_1);
  return;
}

