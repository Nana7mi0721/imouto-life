
void FUN_00678a50(int param_1,undefined4 param_2,char *param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  undefined1 local_460;
  undefined1 auStack_45f [83];
  undefined1 local_40c [8];
  int local_404;
  
  if (param_5 == -1) {
    FUN_006789a0(param_1,param_2,param_3,0);
    return;
  }
  if (param_5 != 0) {
    FUN_00668620(param_1,s_zTXt__invalid_compression_type_00a0d83c);
  }
  iVar2 = FUN_006782a0(param_1,param_2,&local_460);
  if (iVar2 == 0) {
    FUN_00668620(param_1,s_zTXt__invalid_keyword_00a0d824);
  }
  auStack_45f[iVar2] = 0;
  iVar2 = iVar2 + 2;
  if (param_3 == (char *)0x0) {
    iVar3 = 0;
  }
  else {
    uVar4 = 0xffffffff;
    pcVar5 = param_3;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    iVar3 = ~uVar4 - 1;
  }
  FUN_006780a0(local_40c,param_3,iVar3);
  iVar3 = FUN_006780c0(param_1,0x7a545874,local_40c,iVar2);
  if (iVar3 != 0) {
    FUN_00668620(param_1,*(undefined4 *)(param_1 + 0x9c));
  }
  FUN_00677300(param_1,0x7a545874,local_404 + iVar2);
  FUN_00677370(param_1,&local_460,iVar2);
  FUN_00678240(param_1,local_40c);
  FUN_006773b0(param_1);
  return;
}

