
/* Library Function - Single Match
    _crtGetLocaleInfoA@16
   
   Library: Visual Studio 2003 Release
   __stdcall crtGetLocaleInfoA,16 */

int crtGetLocaleInfoA(uint param_1,LCTYPE param_2,LPSTR param_3,int param_4)

{
  int iVar1;
  int iVar2;
  char *_Source;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0x1a;
  do {
    iVar1 = (iVar2 + iVar3) / 2;
    if (param_1 == *(uint *)(&UNK_007d3180 + iVar1 * 0x2c)) {
      if (param_2 == 1) {
        _Source = &DAT_007d3184 + iVar1 * 0x2c;
      }
      else if (param_2 == 3) {
        _Source = &DAT_007d3190 + iVar1 * 0x2c;
      }
      else if (param_2 == 7) {
        _Source = &DAT_007d3198 + iVar1 * 0x2c;
      }
      else if (param_2 == 0xb) {
        _Source = &DAT_007d319c + iVar1 * 0x2c;
      }
      else if (param_2 == 0x1001) {
        _Source = *(char **)(&UNK_007d318c + iVar1 * 0x2c);
      }
      else if (param_2 == 0x1002) {
        _Source = *(char **)(&UNK_007d3194 + iVar1 * 0x2c);
      }
      else {
        if (param_2 != 0x1004) break;
        _Source = &DAT_007d31a4 + iVar1 * 0x2c;
      }
      if ((_Source != (char *)0x0) && (0 < param_4)) {
        _strncpy(param_3,_Source,param_4 - 1);
        param_3[param_4 + -1] = '\0';
        return 1;
      }
      break;
    }
    if (param_1 < *(uint *)(&UNK_007d3180 + iVar1 * 0x2c)) {
      iVar2 = iVar1 + -1;
    }
    else {
      iVar3 = iVar1 + 1;
    }
  } while (iVar3 <= iVar2);
  iVar2 = GetLocaleInfoA(param_1,param_2,param_3,param_4);
  return iVar2;
}

