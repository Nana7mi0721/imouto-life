
void FUN_00678fb0(undefined4 param_1,undefined1 param_2,char *param_3,char *param_4)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  undefined1 local_40;
  char local_3f [63];
  
  uVar2 = 0xffffffff;
  pcVar6 = param_3;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  uVar3 = 0xffffffff;
  pcVar6 = param_4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar4 = ~uVar3 - 1;
  uVar3 = ~uVar3 + uVar2;
  if (0x40 < uVar3) {
    FUN_006687b0(param_1,s_Can_t_write_sCAL__buffer_too_sma_00a0d920);
    return;
  }
  local_40 = param_2;
  pcVar6 = local_3f;
  for (uVar5 = uVar2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)param_3;
    param_3 = param_3 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar5 = uVar2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar6 = *param_3;
    param_3 = param_3 + 1;
    pcVar6 = pcVar6 + 1;
  }
  pcVar6 = local_3f + uVar2;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)param_4;
    param_4 = param_4 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar6 = *param_4;
    param_4 = param_4 + 1;
    pcVar6 = pcVar6 + 1;
  }
  FUN_00677430(param_1,0x7343414c,&local_40,uVar3);
  return;
}

