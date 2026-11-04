
void FUN_006783c0(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined1 local_5c;
  undefined1 local_5b;
  undefined1 local_5a;
  undefined1 local_59;
  undefined1 local_58 [2];
  undefined1 local_56 [2];
  undefined1 local_54 [4];
  undefined1 local_50 [80];
  
  iVar2 = (-(uint)(*(char *)(param_2 + 1) != '\b') & 4) + 6;
  iVar1 = param_2[3];
  iVar3 = FUN_006782a0(param_1,*param_2,local_50);
  if (iVar3 == 0) {
    FUN_00668620(param_1,s_sPLT__invalid_keyword_00a0d614);
  }
  FUN_00677300(param_1,0x73504c54,iVar2 * iVar1 + 2 + iVar3);
  FUN_00677370(param_1,local_50,iVar3 + 1);
  FUN_00677370(param_1,param_2 + 1,1);
  puVar4 = (undefined2 *)param_2[2];
  if (puVar4 < puVar4 + param_2[3] * 5) {
    do {
      if (*(char *)(param_2 + 1) == '\b') {
        local_5c = *(undefined1 *)puVar4;
        local_5b = *(undefined1 *)(puVar4 + 1);
        local_5a = *(undefined1 *)(puVar4 + 2);
        local_59 = *(undefined1 *)(puVar4 + 3);
        FUN_00677270(local_58,puVar4[4]);
      }
      else {
        FUN_00677270(&local_5c,*puVar4);
        FUN_00677270(&local_5a,puVar4[1]);
        FUN_00677270(local_58,puVar4[2]);
        FUN_00677270(local_56,puVar4[3]);
        FUN_00677270(local_54,puVar4[4]);
      }
      FUN_00677370(param_1,&local_5c,iVar2);
      puVar4 = puVar4 + 5;
    } while (puVar4 < (undefined2 *)(param_2[2] + param_2[3] * 10));
  }
  FUN_006773b0(param_1);
  return;
}

