
void FUN_006789a0(undefined4 param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  undefined1 local_50 [80];
  
  iVar2 = FUN_006782a0(param_1,param_2,local_50);
  if (iVar2 == 0) {
    FUN_00668620(param_1,s_tEXt__invalid_keyword_00a0d80c);
  }
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
    pcVar4 = param_3;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3 - 1;
  }
  if (0x7ffffffeU - iVar2 < uVar3) {
    FUN_00668620(param_1,s_tEXt__text_too_long_00a0d7f8);
  }
  FUN_00677300(param_1,0x74455874,uVar3 + 1 + iVar2);
  FUN_00677370(param_1,local_50,iVar2 + 1);
  if (uVar3 != 0) {
    FUN_00677370(param_1,param_3,uVar3);
  }
  FUN_006773b0(param_1);
  return;
}

