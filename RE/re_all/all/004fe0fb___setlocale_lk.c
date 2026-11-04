
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    __setlocale_lk
   
   Library: Visual Studio 2003 Release */

undefined4 __fastcall __setlocale_lk(char *param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  char *pcVar3;
  size_t sVar4;
  int iVar5;
  size_t sVar6;
  undefined4 *puVar7;
  undefined **ppuVar8;
  int local_98;
  int local_90;
  char local_8c [132];
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  if (param_2 == 0) {
    bVar1 = true;
    local_90 = 0;
    if (param_1 != (char *)0x0) {
      if (((*param_1 == 'L') && (param_1[1] == 'C')) && (param_1[2] == '_')) {
        do {
          pcVar3 = _strpbrk(param_1,"=;");
          if (((pcVar3 == (char *)0x0) || (sVar4 = (int)pcVar3 - (int)param_1, sVar4 == 0)) ||
             (*pcVar3 == ';')) {
            return 0;
          }
          local_98 = 1;
          ppuVar8 = &PTR_s_LC_COLLATE_0084b674;
          do {
            iVar5 = _strncmp(*ppuVar8,param_1,sVar4);
            if ((iVar5 == 0) && (sVar6 = _strlen(*ppuVar8), sVar4 == sVar6)) break;
            local_98 = local_98 + 1;
            ppuVar8 = ppuVar8 + 3;
          } while ((int)ppuVar8 < 0x84b6a5);
          pcVar3 = pcVar3 + 1;
          sVar4 = _strcspn(pcVar3,";");
          if ((sVar4 == 0) && (*pcVar3 != ';')) {
            return 0;
          }
          if (local_98 < 6) {
            _strncpy(local_8c,pcVar3,sVar4);
            local_8c[sVar4] = '\0';
            iVar5 = __setlocale_set_cat(local_8c);
            if (iVar5 != 0) {
              local_90 = local_90 + 1;
            }
          }
        } while ((pcVar3[sVar4] != '\0') && (param_1 = pcVar3 + sVar4 + 1, *param_1 != '\0'));
        if (local_90 == 0) {
          return 0;
        }
      }
      else {
        iVar5 = __expandlocale(param_1,local_8c,0,0,0);
        if (iVar5 == 0) {
          return 0;
        }
        puVar7 = &DAT_0084b66c;
        do {
          if ((void **)puVar7 != &DAT_0084b66c) {
            iVar5 = _strcmp(local_8c,(char *)*puVar7);
            if ((iVar5 == 0) || (iVar5 = __setlocale_set_cat(local_8c), iVar5 != 0)) {
              local_90 = local_90 + 1;
            }
            else {
              bVar1 = false;
            }
          }
          puVar7 = puVar7 + 3;
        } while ((int)puVar7 < 0x84b6a9);
        if (bVar1) {
          uVar2 = __setlocale_get_all();
          _free(DAT_0084b66c);
          DAT_0084b66c = (void *)0x0;
          return uVar2;
        }
        if (local_90 == 0) {
          return 0;
        }
      }
    }
    uVar2 = __setlocale_get_all();
  }
  else {
    if (param_1 == (char *)0x0) {
      return (&DAT_0084b66c)[param_2 * 3];
    }
    uVar2 = __setlocale_set_cat(param_1);
  }
  return uVar2;
}

