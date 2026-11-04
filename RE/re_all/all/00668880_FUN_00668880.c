
void FUN_00668880(undefined4 param_1,int param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  char local_c0 [192];
  
  uVar5 = 0;
  do {
    cVar4 = *param_3;
    if (cVar4 == '\0') break;
    if (((param_2 == 0) || (cVar4 != '@')) || (param_3[1] == '\0')) {
LAB_0066891d:
      local_c0[uVar5] = cVar4;
      uVar5 = uVar5 + 1;
    }
    else {
      cVar4 = param_3[1];
      param_3 = param_3 + 1;
      iVar3 = 0;
      cVar1 = DAT_0081e288;
      if (DAT_0081e288 != cVar4) {
        do {
          if (cVar1 == '\0') break;
          cVar1 = (&DAT_0081e289)[iVar3];
          iVar3 = iVar3 + 1;
        } while (cVar1 != cVar4);
        if (7 < iVar3) goto LAB_0066891d;
      }
      for (pcVar2 = (char *)(iVar3 * 0x20 + param_2);
          ((uVar5 < 0xbf && (*pcVar2 != '\0')) && (pcVar2 < (char *)((iVar3 + 1) * 0x20 + param_2)))
          ; pcVar2 = pcVar2 + 1) {
        local_c0[uVar5] = *pcVar2;
        uVar5 = uVar5 + 1;
      }
    }
    param_3 = param_3 + 1;
  } while (uVar5 < 0xbf);
  local_c0[uVar5] = '\0';
  FUN_006687b0(param_1,local_c0);
  return;
}

